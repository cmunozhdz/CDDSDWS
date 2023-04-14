//
//  NSDate+GXStd.h
//  GXStd
//
//  Created by Marcos Crispino on 26/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

@interface NSDate (GXStd)

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Date & DateTime

/// Returns YES if date has values smaller than days, NO otherwise
//- (BOOL)isGxDateTime; NSDate+GXDateTime

/// Ensures date has no value smaller than seconds (yyyy-MM-dd HH:mm:ss)
//- (NSDate *)gxDateTimeNSDate; NSDate+GXDateTime
/// Ensures date has no value smaller than milliseconds (yyyy-MM-dd HH:mm:ss.SSS)
//- (NSDate *)gxDateTimeNSDateMS; NSDate+GXDateTime
/// Ensures date has no value smaller than days (yyyy-MM-dd)
//- (NSDate *)gxDateNSDate; NSDate+GXDateTime
/// Ensures date has no value smaller than seconds and has no values (same as empty) greater than hours (HH:mm:ss)
//- (NSDate *)gxTimeOnlyDateTimeNSDate; NSDate+GXDateTime
/// Ensures date has no value smaller than milliseconds and has no values (same as empty) greater than hours (HH:mm:ss)
//- (NSDate *)gxTimeOnlyDateTimeNSDateMS; NSDate+GXDateTime

#pragma mark - Constructing dates from its components

+ (NSDate *)gxDateFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day;
+ (NSDate *)gxDateTimeFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day hour:(nullable NSNumber*)hour minute:(nullable NSNumber*)minute second:(nullable NSNumber*)second;
+ (NSDate *)gxDateTimeFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day hour:(nullable NSNumber*)hour minute:(nullable NSNumber*)minute second:(nullable NSNumber*)second millisecond:(NSNumber *)millisecond;
+ (NSDate *)gxDateTimeFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day hour:(nullable NSNumber*)hour minute:(nullable NSNumber*)minute;
+ (NSDate *)gxDateTimeFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day hour:(nullable NSNumber*)hour;
+ (NSDate *)gxDateTimeFromYear:(NSNumber*)year month:(NSNumber*)month day:(NSNumber*)day;

+ (NSDate *)gxTimeOnlyDateTimeFromHour:(NSNumber *)hour minute:(NSNumber *)minute second:(NSNumber *)second;
+ (NSDate *)gxTimeOnlyDateTimeFromHour:(NSNumber *)hour minute:(NSNumber *)minute second:(NSNumber *)second millisecond:(nullable NSNumber *)millisecond;

#pragma mark - Now & Today

+ (NSDate *)gxCurrentDate;
+ (NSDate *)gxCurrentDateTime;
+ (NSDate *)gxCurrentDateTimeMS;

#pragma mark - Accessing date & time components

// Date or DateTime
- (NSNumber *)gxDateDay; // @([self gxDateDayInteger])
- (NSNumber *)gxDateTimeDay; // @([self gxDateTimeDayInteger])

- (NSInteger)gxDayInteger:(NSCalendar *)calendar;
- (NSInteger)gxDateDayInteger; // return [self gxDayInteger:NSCalendar.gxCalendar];
- (NSInteger)gxDateTimeDayInteger; // [self gxDayInteger:NSCalendar.gxCalendarCurrentTimeZone];


- (NSNumber *)gxDateMonth; // @([self gxDateMonthInteger])
- (NSNumber *)gxDateTimeMonth; // @([self gxDateTimeMonthInteger])

- (NSInteger)gxMonthInteger:(NSCalendar *)calendar;
- (NSInteger)gxDateMonthInteger; // return [self gxMonthInteger:NSCalendar.gxCalendar];
- (NSInteger)gxDateTimeMonthInteger; // [self gxMonthInteger:NSCalendar.gxCalendarCurrentTimeZone];


- (NSNumber *)gxDateYear; // @([self gxDateYearInteger])
- (NSNumber *)gxDateTimeYear; // @([self gxDateTimeYearInteger])

- (NSInteger)gxYearInteger:(NSCalendar *)calendar;
- (NSInteger)gxDateYearInteger; // return [self gxYearInteger:NSCalendar.gxCalendar];
- (NSInteger)gxDateTimeYearInteger; // [self gxYearInteger:NSCalendar.gxCalendarCurrentTimeZone];

// DateTime
- (NSNumber *)gxSeconds; // @([self gxSecondsInteger])
- (NSInteger)gxSecondsInteger; // [self gxSecondsInteger:NSCalendar.gxCalendarCurrentTimeZone]
- (NSInteger)gxSecondsInteger:(NSCalendar *)calendar;

- (NSNumber *)gxMinutes; // @([self gxMinutesInteger])
- (NSInteger)gxMinutesInteger; // [self gxMinutesInteger:NSCalendar.gxCalendarCurrentTimeZone]
- (NSInteger)gxMinutesInteger:(NSCalendar *)calendar;

- (NSNumber *)gxHours; // @([self gxHoursInteger])
- (NSInteger)gxHoursInteger; // [self gxHoursInteger:NSCalendar.gxCalendarCurrentTimeZone]
- (NSInteger)gxHoursInteger:(NSCalendar *)calendar;

- (NSNumber *)gxMilliseconds; // @([self gxMillisecondsInteger])
- (NSInteger)gxMillisecondsInteger; // [self gxMillisecondsInteger:NSCalendar.gxCalendarCurrentTimeZone]
- (NSInteger)gxMillisecondsInteger:(NSCalendar *)calendar;

#pragma mark - Adding components

- (NSDate *)gxDateByAddingDays:(NSNumber *)days;
- (NSDate *)gxDateTimeByAddingDays:(NSNumber *)days;

- (NSDate *)gxDateByAddingMonths:(NSNumber *)months;
- (NSDate *)gxDateTimeByAddingMonths:(NSNumber *)months;

- (NSDate *)gxDateByAddingYears:(NSNumber *)years;
- (NSDate *)gxDateTimeByAddingYears:(NSNumber *)years;

- (NSDate *)gxDateTimeByAddingMilliseconds:(NSNumber *)milliseconds;
- (NSDate *)gxDateTimeByAddingSeconds:(NSNumber *)seconds;
- (NSDate *)gxDateTimeByAddingHours:(NSNumber *)hours;
- (NSDate *)gxDateTimeByAddingMinutes:(NSNumber *)minutes;

- (NSNumber *)gxDateDifferenceWith:(NSDate *)date;
- (NSNumber *)gxDateTimeDifferenceWith:(NSDate *)dtime;

#pragma mark - Operating with dates

- (NSNumber *)impl_gxSecondsToDate:(NSDate *)date;
- (NSNumber *)impl_gxSecondsWithMillisecondsToDate:(NSDate *)date;
- (NSNumber *)impl_gxAge:(NSDate *)endDate;
- (NSNumber *)impl_gxAge;

- (NSDate *)gxDateTimeWithZeroSeconds;

#pragma mark - Calculated properties

- (NSDate *)gxDateEndOfMonth;
- (NSDate *)gxDateTimeEndOfMonth;

- (NSNumber *)gxDateDayOfWeek; // [self gxDayOfWeekWithCalendar:NSCalendar.gxCalendar]
- (NSNumber *)gxDateTimeDayOfWeek; // [self gxDayOfWeekWithCalendar:NSCalendar.gxCalendarCurrentTimeZone]
- (NSNumber *)gxDayOfWeekWithCalendar:(NSCalendar *)calendar;

#pragma mark - Static methods

+ (NSString *)gxTime;

#pragma mark - Converting from string

+ (NSDate *)gxCharToTime:(NSString *)str;
+ (NSDate *)gxCharToTime:(NSString *)str format:(NSInteger)format;
+ (NSDate *)gxCharToDate:(NSString *)str;
+ (NSDate *)gxCharToDate:(NSString *)str format:(NSInteger)format;

#pragma mark - Converting to string

- (NSString *)gxDateCharDayOfWeek; // [self gxDateCharDayOfWeekWithLanguage:nil]
- (NSString *)gxDateCharDayOfWeekWithLanguage:(nullable NSString *)lang; // [self gxCharDayOfWeekWithLanguage:lang timeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]]
- (NSString *)gxDateTimeCharDayOfWeek; // [self gxDateTimeCharDayOfWeekWithLanguage:nil]
- (NSString *)gxDateTimeCharDayOfWeekWithLanguage:(nullable NSString *)lang; // [self gxCharDayOfWeekWithLanguage:lang timeZone:GXTimeZone.currentTimeZoneWithUTCConversionIfNeeded]
- (NSString *)gxCharDayOfWeekWithLanguage:(nullable NSString *)lang timeZone:(NSTimeZone *)timeZone;;

- (NSString *)gxDateCharMonth; // [self gxDateCharMonthWithLanguage:nil]
- (NSString *)gxDateCharMonthWithLanguage:(nullable NSString *)lang; // [self gxCharMonthWithLanguage:lang timeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]]
- (NSString *)gxDateTimeCharMonth; // [self gxDateTimeCharMonthWithLanguage:nil]
- (NSString *)gxDateTimeCharMonthWithLanguage:(nullable NSString *)lang; // [self gxCharMonthWithLanguage:lang timeZone:GXTimeZone.currentTimeZoneWithUTCConversionIfNeeded]
- (NSString *)gxCharMonthWithLanguage:(nullable NSString *)lang timeZone:(NSTimeZone *)timeZone;

- (NSString *)gxDateToString;
- (NSString *)gxDateToStringWithFormat:(NSInteger)format;
- (NSString *)gxDateToStringWithFormat:(NSInteger)format delimiter:(NSString *)sep;
- (NSString *)gxDateToStringWithPicture:(NSString *)picture;

- (NSString *)gxTimeToString;
- (NSString *)gxTimeToStringWithDateLength:(NSInteger)dLen timeLength:(NSInteger)tLen amPm:(NSInteger)amPM format:(NSInteger)format dateSeparator:(NSString *)dSep timeSeparator:(NSString *)tSep dateTimeSeparator:(NSString *)dtSep;

#pragma mark -

/**
 * Removes the date from a datetime, returning only the time as a new datetime.
 * The time returned is expressed in the current timezone.
 */
+ (NSDate *)gxDateByRemovingDatePartFromDate:(NSDate *)date;

/**
 * Removes the time from a datetime, returning only the date as a new datetime
 */
+ (NSDate *)gxDateByRemovingTimePartFromDate:(NSDate *)date;

/**
 * Converts the given date (must be in device timezone) to UTC
 */
+ (NSDate *)gxDateToUTC:(NSDate *)date;

/**
 * Converts the given date time (must be in device timezone) to UTC
 */
+ (NSDate *)gxDateTimeToUTC:(NSDate *)date;

#pragma mark - Empty

- (NSNumber *)gxIsEmpty;

NS_ASSUME_NONNULL_END

@end
