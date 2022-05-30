//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTLogger;

PT_EXTERN
PT_OBJC_RUNTIME_NAME(Logger)
@interface PTLogger : NSObject

@property (nonatomic, class, readonly, strong) PTLogger *sharedLogger NS_SWIFT_NAME(shared);

@property (nonatomic, copy, nullable) NSString *tag;

- (void)logMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

- (void)traceMessage:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

@end

NS_ASSUME_NONNULL_END
