/*
 Modified MIT License

 Copyright 2022 OneSignal

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

import Foundation
import OneSignalOSCore
import OneSignalCore

class OSIdentityOperationExecutor: OSOperationExecutor {
    var supportedOperations: [String] = ["OSUpdateIdentityOperation"] // TODO: Don't hardcode
    var queue: [OSOperation] = []
    
    /**
     For the Identity Model change requests, we enqueue each operation as a separate request.
     */
    func enqueue(_ operation: OSOperation) {
        print("🔥 OSIdentityOperationExecutor enqueue \(operation)")
        // Cache the operation
        OneSignalUserDefaults.initShared().saveObject(forKey: operation.operationId.uuidString, withValue: operation)
        queue.append(operation)
    }
    


    
    func execute() {
        if queue.isEmpty {
            return
        }
            
        let operation = queue.removeFirst()
        // Execute the operation
        
        // Mock a response
        
        let response = ["language": "en"]
        
        // On success, remove operation from cache, and hydrate model
        OneSignalUserDefaults.initShared().removeValue(forKey: operation.operationId.uuidString)

        operation.model.hydrate(response)
        // On failure, retry logic, but order of operations matters
    }
    
}
