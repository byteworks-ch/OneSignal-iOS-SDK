#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.9.2 (swiftlang-5.9.2.2.56 clang-1500.1.0.2.5)
#ifndef ONESIGNALOSCORE_SWIFT_H
#define ONESIGNALOSCORE_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
@import OneSignalCore;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="OneSignalOSCore",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)

@class NSString;

SWIFT_PROTOCOL("_TtP15OneSignalOSCore23OSBackgroundTaskHandler_")
@protocol OSBackgroundTaskHandler
- (void)beginBackgroundTask:(NSString * _Nonnull)taskIdentifier;
- (void)endBackgroundTask:(NSString * _Nonnull)taskIdentifier;
- (void)setTaskInvalid:(NSString * _Nonnull)taskIdentifier;
@end


SWIFT_CLASS("_TtC15OneSignalOSCore23OSBackgroundTaskManager")
@interface OSBackgroundTaskManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, strong) id <OSBackgroundTaskHandler> _Nullable taskHandler;)
+ (id <OSBackgroundTaskHandler> _Nullable)taskHandler SWIFT_WARN_UNUSED_RESULT;
+ (void)setTaskHandler:(id <OSBackgroundTaskHandler> _Nullable)value;
+ (void)beginBackgroundTask:(NSString * _Nonnull)taskIdentifier;
+ (void)endBackgroundTask:(NSString * _Nonnull)taskIdentifier;
+ (void)setTaskInvalid:(NSString * _Nonnull)taskIdentifier;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNumber;
@class OSReadYourWriteData;

SWIFT_PROTOCOL("_TtP15OneSignalOSCore11OSCondition_")
@protocol OSCondition
@property (nonatomic, readonly, copy) NSString * _Nonnull conditionId;
- (BOOL)isMetWithIndexedTokens:(NSDictionary<NSString *, NSDictionary<NSNumber *, OSReadYourWriteData *> *> * _Nonnull)indexedTokens SWIFT_WARN_UNUSED_RESULT;
- (OSReadYourWriteData * _Nullable)getNewestTokenWithIndexedTokens:(NSDictionary<NSString *, NSDictionary<NSNumber *, OSReadYourWriteData *> *> * _Nonnull)indexedTokens SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC15OneSignalOSCore20OSConsistencyManager")
@interface OSConsistencyManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) OSConsistencyManager * _Nonnull shared;)
+ (OSConsistencyManager * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (OSReadYourWriteData * _Nullable)getRywTokenFromAwaitableCondition:(id <OSCondition> _Nonnull)condition forId:(NSString * _Nonnull)id SWIFT_WARN_UNUSED_RESULT;
- (void)resolveConditionsWithIDWithId:(NSString * _Nonnull)id;
@end

@class NSCoder;

SWIFT_CLASS("_TtC15OneSignalOSCore7OSDelta")
@interface OSDelta : NSObject <NSCoding>
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (void)encodeWithCoder:(NSCoder * _Nonnull)coder;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OneSignalOSCore24OSIamFetchReadyCondition")
@interface OSIamFetchReadyCondition : NSObject <OSCondition>
+ (OSIamFetchReadyCondition * _Nonnull)sharedInstanceWithId:(NSString * _Nonnull)id SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CONDITIONID;)
+ (NSString * _Nonnull)CONDITIONID SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, copy) NSString * _Nonnull conditionId;
- (BOOL)isMetWithIndexedTokens:(NSDictionary<NSString *, NSDictionary<NSNumber *, OSReadYourWriteData *> *> * _Nonnull)indexedTokens SWIFT_WARN_UNUSED_RESULT;
- (OSReadYourWriteData * _Nullable)getNewestTokenWithIndexedTokens:(NSDictionary<NSString *, NSDictionary<NSNumber *, OSReadYourWriteData *> *> * _Nonnull)indexedTokens SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Provides access to OneSignal LiveActivities.
SWIFT_PROTOCOL("_TtP15OneSignalOSCore16OSLiveActivities_")
@protocol OSLiveActivities
/// Indicate this device has entered a live activity, identified within OneSignal by the <code>activityId</code>.
/// <ul>
///   <li>
///     Parameters
///     <ul>
///       <li>
///         activityId: The activity identifier the live activity on this device will receive updates for.
///       </li>
///       <li>
///         withToken: The live activity’s update token to receive the updates.
///       </li>
///     </ul>
///   </li>
/// </ul>
+ (void)enter:(NSString * _Nonnull)activityId withToken:(NSString * _Nonnull)withToken;
/// Indicate this device has entered a live activity, identified within OneSignal by the <code>activityId</code>. This method is deprecated since
/// the request to enter a live activity will always succeed.
/// <ul>
///   <li>
///     Parameters
///     <ul>
///       <li>
///         activityId: The activity identifier the live activity on this device will receive updates for.
///       </li>
///       <li>
///         withToken: The live activity’s update token to receive the updates.
///       </li>
///       <li>
///         withSuccess: A success callback that will be called when the live activity enter request has been queued.
///       </li>
///       <li>
///         withFailure: A failure callback that will be called when the live activity enter request was not successfully queued.
///       </li>
///     </ul>
///   </li>
/// </ul>
+ (void)enter:(NSString * _Nonnull)activityId withToken:(NSString * _Nonnull)withToken withSuccess:(OSResultSuccessBlock _Nullable)withSuccess withFailure:(OSFailureBlock _Nullable)withFailure SWIFT_DEPRECATED;
/// Indicate this device has exited a live activity, identified within OneSignal by the <code>activityId</code>.
/// <ul>
///   <li>
///     Parameters
///     <ul>
///       <li>
///         activityId: The activity identifier the live activity on this device will no longer receive updates for.
///       </li>
///     </ul>
///   </li>
/// </ul>
+ (void)exit:(NSString * _Nonnull)activityId;
/// Indicate this device has exited a live activity, identified within OneSignal by the <code>activityId</code>. This method is deprecated since
/// the request to enter a live activity will always succeed.
/// <ul>
///   <li>
///     Parameters
///     <ul>
///       <li>
///         activityId: The activity identifier the live activity on this device will no longer receive updates for.
///       </li>
///       <li>
///         withSuccess: A success callback that will be called when the live activity exit request has been queued.
///       </li>
///       <li>
///         withFailure: A failure callback that will be called when the live activity enter exit was not successfully queued.
///       </li>
///     </ul>
///   </li>
/// </ul>
+ (void)exit:(NSString * _Nonnull)activityId withSuccess:(OSResultSuccessBlock _Nullable)withSuccess withFailure:(OSFailureBlock _Nullable)withFailure SWIFT_DEPRECATED;
@end


SWIFT_CLASS("_TtC15OneSignalOSCore7OSModel")
@interface OSModel : NSObject <NSCoding>
- (void)encodeWithCoder:(NSCoder * _Nonnull)coder;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OneSignalOSCore18OSModelChangedArgs")
@interface OSModelChangedArgs : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// The OSOperationRepo is a static singleton.
/// OSDeltas are enqueued when model store observers observe changes to their models, and sorted to their appropriate executors.
SWIFT_CLASS("_TtC15OneSignalOSCore15OSOperationRepo")
@interface OSOperationRepo : NSObject
- (void)addFlushDeltaQueueToDispatchQueueInBackground:(BOOL)inBackground;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15OneSignalOSCore19OSReadYourWriteData")
@interface OSReadYourWriteData : NSObject
@property (nonatomic, readonly, copy) NSString * _Nullable rywToken;
@property (nonatomic, readonly, strong) NSNumber * _Nullable rywDelay;
- (nonnull instancetype)initWithRywToken:(NSString * _Nullable)rywToken rywDelay:(NSNumber * _Nullable)rywDelay OBJC_DESIGNATED_INITIALIZER;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly) NSUInteger hash;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15OneSignalOSCore20OSStubLiveActivities")
@interface OSStubLiveActivities : NSObject <OSLiveActivities>
+ (Class _Nonnull)liveActivities SWIFT_WARN_UNUSED_RESULT;
+ (void)enter:(NSString * _Nonnull)activityId withToken:(NSString * _Nonnull)withToken;
+ (void)enter:(NSString * _Nonnull)activityId withToken:(NSString * _Nonnull)withToken withSuccess:(OSResultSuccessBlock _Nullable)withSuccess withFailure:(OSFailureBlock _Nullable)withFailure;
+ (void)exit:(NSString * _Nonnull)activityId;
+ (void)exit:(NSString * _Nonnull)activityId withSuccess:(OSResultSuccessBlock _Nullable)withSuccess withFailure:(OSFailureBlock _Nullable)withFailure;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
