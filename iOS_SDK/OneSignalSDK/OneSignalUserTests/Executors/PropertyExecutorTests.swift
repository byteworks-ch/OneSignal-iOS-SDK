/*
 Modified MIT License
 
 Copyright 2024 OneSignal
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 1. The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 2. All copies of substantial portions of the Software may only be used in connection
with services provided by OneSignal.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

import XCTest
import OneSignalCore
import OneSignalOSCore
import OneSignalCoreMocks
import OneSignalOSCoreMocks
import OneSignalUserMocks
@testable import OneSignalUser

private class Mocks: OneSignalExecutorMocks {
    var propertyExecutor: OSPropertyOperationExecutor!

    override init() {
        super.init()
        propertyExecutor = OSPropertyOperationExecutor(newRecordsState: newRecordsState, jwtConfig: jwtConfig)
    }
}

final class PropertyExecutorTests: XCTestCase {

    override func setUpWithError() throws {
        OneSignalCoreMocks.clearUserDefaults()
        OneSignalUserMocks.reset()
        // App ID is set because requests have guards against null App ID
        OneSignalConfigManager.setAppId("test-app-id")
        // Temp. logging to help debug during testing
        OneSignalLog.setLogLevel(.LL_VERBOSE)
    }

    override func tearDownWithError() throws { }
    
    func testUpdateTagsSendsWhenProcessed() {
        /* Setup */
        let mocks = Mocks()
        mocks.setAuthRequired(false)
        OneSignalUserManagerImpl.sharedInstance.operationRepo.paused = true
        
        let user = mocks.setUserManagerInternalUser(externalId: userA_EUID, onesignalId: userA_OSID)
        let tags = ["testUserA" : "true"]
        MockUserRequests.setAddTagsResponse(with: mocks.client, tags: tags)
        mocks.propertyExecutor.enqueueDelta(OSDelta(name: OS_UPDATE_PROPERTIES_DELTA, identityModelId: user.identityModel.modelId, model: OSPropertiesModel(changeNotifier: OSEventProducer()), property: "tags", value:tags))

        /* When */
        mocks.propertyExecutor.processDeltaQueue(inBackground: false)
        OneSignalCoreMocks.waitForBackgroundThreads(seconds: 0.5)
        
        /* Then */
        XCTAssertTrue(mocks.client.hasExecutedRequestOfType(OSRequestUpdateProperties.self))
    }
    
    func testUpdateTags_IdentityVerificationRequired_butNoToken() {
        /* Setup */
        let mocks = Mocks()
        mocks.setAuthRequired(true)
        OneSignalUserManagerImpl.sharedInstance.operationRepo.paused = true
        
        let user = mocks.setUserManagerInternalUser(externalId: userA_EUID, onesignalId: userA_OSID)
        let tags = ["testUserA" : "true"]
        MockUserRequests.setAddTagsResponse(with: mocks.client, tags: tags)
        mocks.propertyExecutor.enqueueDelta(OSDelta(name: OS_UPDATE_PROPERTIES_DELTA, identityModelId: user.identityModel.modelId, model: OSPropertiesModel(changeNotifier: OSEventProducer()), property: "tags", value:tags))

        /* When */
        mocks.propertyExecutor.processDeltaQueue(inBackground: false)
        OneSignalCoreMocks.waitForBackgroundThreads(seconds: 0.5)
        
        /* Then */
        XCTAssertFalse(mocks.client.hasExecutedRequestOfType(OSRequestUpdateProperties.self))
    }
    
    func testUpdateTags_IdentityVerificationRequired_withToken() {
        /* Setup */
        let mocks = Mocks()
        mocks.setAuthRequired(true)
        OneSignalUserManagerImpl.sharedInstance.operationRepo.paused = true
        
        let user = mocks.setUserManagerInternalUser(externalId: userA_EUID, onesignalId: userA_OSID)
        user.identityModel.jwtBearerToken = userA_JwtToken
        let tags = ["testUserA" : "true"]
        MockUserRequests.setAddTagsResponse(with: mocks.client, tags: tags)
        mocks.propertyExecutor.enqueueDelta(OSDelta(name: OS_UPDATE_PROPERTIES_DELTA, identityModelId: user.identityModel.modelId, model: OSPropertiesModel(changeNotifier: OSEventProducer()), property: "tags", value:tags))

        /* When */
        mocks.propertyExecutor.processDeltaQueue(inBackground: false)
        OneSignalCoreMocks.waitForBackgroundThreads(seconds: 0.5)
        
        /* Then */
        XCTAssertTrue(mocks.client.hasExecutedRequestOfType(OSRequestUpdateProperties.self))
    }
    
    func testCreateUser_IdentityVerificationRequired_withInvalidToken() {
        /* Setup */
        let mocks = Mocks()
        mocks.setAuthRequired(true)
        OneSignalUserManagerImpl.sharedInstance.operationRepo.paused = true
        
        let user = mocks.setUserManagerInternalUser(externalId: userA_EUID, onesignalId: userA_OSID)
        user.identityModel.jwtBearerToken = userA_JwtToken
        
        
        
        let tags = ["testUserA" : "true"]
        MockUserRequests.setUnauthorizedUpdatePropertiesFailureResponses(with: mocks.client, tags: tags)
        mocks.propertyExecutor.enqueueDelta(OSDelta(name: OS_UPDATE_PROPERTIES_DELTA, identityModelId: user.identityModel.modelId, model: OSPropertiesModel(changeNotifier: OSEventProducer()), property: "tags", value:tags))

        var invalidatedCallbackWasCalled = false
        OneSignalUserManagerImpl.sharedInstance.User.onJwtInvalidated { event in
            XCTAssertTrue(event.message == "token has invalid claims: token is expired")
            invalidatedCallbackWasCalled = true
        }
        
        /* When */
        mocks.propertyExecutor.processDeltaQueue(inBackground: false)
        OneSignalCoreMocks.waitForBackgroundThreads(seconds: 0.5)
        
        /* Then */
        XCTAssertTrue(mocks.client.hasExecutedRequestOfType(OSRequestUpdateProperties.self))
        XCTAssertTrue(invalidatedCallbackWasCalled)
    }
}
