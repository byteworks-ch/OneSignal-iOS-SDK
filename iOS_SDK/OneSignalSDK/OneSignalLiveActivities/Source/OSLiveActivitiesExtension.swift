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

import OneSignalOSCore
import ActivityKit

public extension OSLiveActivities {
    /**
     Enable the OneSignalSDK to setup the provided`ActivityAttributes` structure, which conforms to the
     `OneSignalLiveActivityAttributes`. When using this function, OneSignal will manage the capturing
     and synchronizing of both pushToStart and pushToUpdate tokens.
     - Parameters
        - activityType: The specific `OneSignalLiveActivityAttributes` structure tied to the live activity.
        - options: An optional structure to provide for more granular setup options.
     */
    @available(iOS 16.1, *)
    static func setup<T: OneSignalLiveActivityAttributes>(_ activityType: T.Type, options: LiveActivitySetupOptions? = nil) {
        OneSignalLiveActivitiesManagerImpl.setup(activityType, options: options)
    }

    /**
     Indicate this device is capable of receiving pushToStart live activities for the `activityType`.
     - Parameters
        - activityType: The specific `ActivityAttributes` structure tied to the live activity.
        - withToken: The activity type's pushToStart token.
     */
    @available(iOS 17.2, *)
    static func setPushToStartToken<T: ActivityAttributes>(_ activityType: T.Type, withToken: String) {
        OneSignalLiveActivitiesManagerImpl.setPushToStartToken(activityType, withToken: withToken)
    }

    /**
     Indicate this device is no longer capable of receiving pushToStart live activities for the `activityType`.
     - Parameters
        - activityType: The specific `ActivityAttributes` structure tied to the live activity.
     */
    @available(iOS 17.2, *)
    static func removePushToStartToken<T: ActivityAttributes>(_ activityType: T.Type) {
        OneSignalLiveActivitiesManagerImpl.removePushToStartToken(activityType)
    }
}

/**
 The setup options for `OneSignal.LiveActivities.setup`.
 */
public struct LiveActivitySetupOptions {
    /**
     When true, OneSignal will listen for pushToStart tokens for the `OneSignalLiveActivityAttributes` structure.
     */
    public var enablePushToStart: Bool = true

    /**
     When true, OneSignal will listen for pushToUpdate  tokens for each start live activity that uses the
     `OneSignalLiveActivityAttributes` structure.
     */
    public var enablePushToUpdate: Bool = true
}
