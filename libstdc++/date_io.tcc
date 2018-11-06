
#pragma GCC system_header

namespace std {
namespace chrono {

  // DURATION I/O

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const duration<_Rep, _Period>& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const duration<_Rep, _Period>& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep,
	   typename _Period, typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
	        duration<_Rep, _Period>& __d,
	        basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
	        minutes* __offset = nullptr)
    {
      return __is;
    }

  // TIME_POINT I/O

  // OPERATOR<<

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const sys_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const local_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const sys_days& __dp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const utc_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const tai_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const gps_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const file_time<_Duration>& __tp)
    {
      return __os;
    }

  // TO_STREAM

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const sys_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const local_time<_Duration>& __tp,
	      const string* __abbrev = nullptr,
	      const seconds* __offset_sec = nullptr)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const utc_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const tai_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const gps_time<_Duration>& __tp)
    {
      return __os;

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const file_time<_Duration>& __tp)
    {
      return __os;
    }

  // FROM_STREAM

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		sys_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		local_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		utc_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		tai_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		gps_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		file_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // DAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const day& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const day& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		day& __d,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // MONTH

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const month& __m)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month& __m)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month& __m,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // YEAR

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const year& __y)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year& __y)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year& __y,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // WEEKDAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const weekday& __wd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const weekday& __wd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		weekday& __wd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // WEEKDAY_INDEXED

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const weekday_indexed& __wdi)
    {
      return __os;
    }

  // WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const weekday_last& __wdl)
    {
      return __os;
    }

  // MONTH_DAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const month_day& __md)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month_day& __md)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month_day& __md,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // MONTH_DAY_LAST

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_day_last& __mdl)
    {
      return __os;
    }

  // MONTH_WEEKDAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday& __mwd)
    {
      return __os;
    }

  // MONTH_WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday_last& __mwdl)
    {
      return __os;
    }

  // YEAR_MONTH

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month& __ym)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month& __ym)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month& __ym,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // YEAR_MONTH_DAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day& __ymd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month_day& __ymd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month_day& __ymd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr)
    {
      return __is;
    }

  // YEAR_MONTH_DAY_LAST

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day_last& __ymdl)
    {
      return __os;
    }

  // YEAR_MONTH_WEEKDAY

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday& __ymwdi)
    {
      return __os;
    }

  // YEAR_MONTH_WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday_last& __ymwdl)
    {
      return __os;
    }

  // CALENDAR COMPOSITION OPERATORS

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<hours>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<minutes>& __t);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<seconds>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<duration<_Rep, _Period>>& __t)
    {
      return __os;
    }

  // INFORMATION CLASSES

  struct sys_info;
  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const sys_info& __si)
    {
      return __os;
    }

  struct local_info;
  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const local_info& __li)
    {
      return __os;
    }

  // ZONED_TIME

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const zoned_time<_Duration, _TimeZonePtr>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const zoned_time<_Duration, _TimeZonePtr>& __tp)
    {
      return __os;
    }

} // namespace chrono
} // namespace std

#include "date_io.tcc"

