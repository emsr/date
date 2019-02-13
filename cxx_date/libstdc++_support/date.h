
#include <chrono>
#include <ostream>
#include <vector>
#include <string>
#include <atomic>

#pragma GCC system_header

// This could use a dose of <=> ...

namespace std {
namespace chrono {

  template<typename _Int>
    constexpr _Int
    modulo(_Int __num, _Int __den)
    { return /*FIXME*/0; }

  namespace __detail
  {
    constexpr int
    __days_per_month[12]
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    constexpr int
    __last_day[12]
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  }

  // TRAITS

  template<typename _Tp>
    struct is_clock;

  template<typename _Tp>
    inline constexpr bool
    is_clock_v = is_clock<_Tp>::value;

  // DURATION I/O

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const duration<_Rep, _Period>& __d);

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const duration<_Rep, _Period>& __d);

  template<typename _CharT, typename _Traits, typename _Rep,
	   typename _Period, typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
	        duration<_Rep, _Period>& __d,
	        basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
	        minutes* __offset = nullptr);

  // TYPEDEFS

  // We are tacitly assuming 'int' is sufficient for these
  // in the math operators below.

  // signed integer type of at least 25 bits
  using days = duration<int, ratio_multiply<ratio<24>, hours::period>>;
  // signed integer type of at least 22 bits
  using weeks = duration<int, ratio_multiply<ratio<7>, days::period>>;
  // signed integer type of at least 17 bits
  using years = duration<int, ratio_multiply<ratio<146097, 400>, days::period>>;
  // signed integer type of at least 20 bits
  using months = duration<int, ratio_divide<years::period, ratio<12>>>;

  // CLASS DECLARATIONS
  class day;
  class month;
  class year;
  class weekday;
  class weekday_indexed;
  class weekday_last;
  class month_day;
  class month_day_last;
  class month_weekday;
  class month_weekday_last;
  class year_month;
  class year_month_day;
  class year_month_day_last;
  class year_month_weekday;
  class year_month_weekday_last;
  class nonexistent_local_time;
  class ambiguous_local_time;
  class time_zone;
  class tzdb_list;
  class leap;
  class link;

  struct last_spec
  {
    explicit last_spec() = default;
  };

  constexpr last_spec last{};

  // CALENDAR COMPOSITION OPERATORS

  constexpr year_month
  operator/(const year& __y, const month& __m) noexcept;

  constexpr year_month
  operator/(const year& __y, int __m) noexcept;

  constexpr month_day
  operator/(const month& __m, const day& __d) noexcept;

  constexpr month_day
  operator/(const month& __m, int __d) noexcept;

  constexpr month_day
  operator/(int __m, const day& __d) noexcept;

  constexpr month_day
  operator/(const day& __d, const month& __m) noexcept;

  constexpr month_day
  operator/(const day& __d, int __m) noexcept;

  constexpr month_day_last
  operator/(const month& __m, last_spec) noexcept;

  constexpr month_day_last
  operator/(int __m, last_spec) noexcept;

  constexpr month_day_last
  operator/(last_spec, const month& __m) noexcept;

  constexpr month_day_last
  operator/(last_spec, int __m) noexcept;

  constexpr month_weekday
  operator/(const month& __m, const weekday_indexed& __wdi) noexcept;

  constexpr month_weekday
  operator/(int __m, const weekday_indexed& __wdi) noexcept;

  constexpr month_weekday
  operator/(const weekday_indexed& __wdi, const month& __m) noexcept;

  constexpr month_weekday
  operator/(const weekday_indexed& __wdi, int __m) noexcept;

  constexpr month_weekday_last
  operator/(const month& __m, const weekday_last& __wdl) noexcept;

  constexpr month_weekday_last
  operator/(int __m, const weekday_last& __wdl) noexcept;

  constexpr month_weekday_last
  operator/(const weekday_last& __wdl, const month& __m) noexcept;

  constexpr month_weekday_last
  operator/(const weekday_last& __wdl, int __m) noexcept;

  constexpr year_month_day
  operator/(const year_month& __ym, const day& __d) noexcept;

  constexpr year_month_day
  operator/(const year_month& __ym, int __d) noexcept;

  constexpr year_month_day
  operator/(const year& __y, const month_day& __md) noexcept;

  constexpr year_month_day
  operator/(int __y, const month_day& __md) noexcept;

  constexpr year_month_day
  operator/(const month_day& __md, const year& __y) noexcept;

  constexpr year_month_day
  operator/(const month_day& __md, int __y) noexcept;

  constexpr year_month_day_last
  operator/(const year_month& __ym, last_spec) noexcept;

  constexpr year_month_day_last
  operator/(const year& __y, const month_day_last& __mdl) noexcept;

  constexpr year_month_day_last
  operator/(int __y, const month_day_last& __mdl) noexcept;

  constexpr year_month_day_last
  operator/(const month_day_last& __mdl, const year& __y) noexcept;

  constexpr year_month_day_last
  operator/(const month_day_last& __mdl, int __y) noexcept;

  constexpr year_month_weekday
  operator/(const year_month& __ym, const weekday_indexed& __wdi) noexcept;

  constexpr year_month_weekday
  operator/(const year& __y, const month_weekday& __mwd) noexcept;

  constexpr year_month_weekday
  operator/(int __y, const month_weekday& __mwd) noexcept;

  constexpr year_month_weekday
  operator/(const month_weekday& __mwd, const year& __y) noexcept;

  constexpr year_month_weekday
  operator/(const month_weekday& __mwd, int __y) noexcept;

  constexpr year_month_weekday_last
  operator/(const year_month& __ym, const weekday_last& __wdl) noexcept;

  constexpr year_month_weekday_last
  operator/(const year& __y, const month_weekday_last& __mwdl) noexcept;

  constexpr year_month_weekday_last
  operator/(int __y, const month_weekday_last& __mwdl) noexcept;

  constexpr year_month_weekday_last
  operator/(const month_weekday_last& __mwdl, const year& __y) noexcept;

  constexpr year_month_weekday_last
  operator/(const month_weekday_last& __mwdl, int __y) noexcept;

  // OTHER CALENDAR OPERATORS

  constexpr year_month_day_last
  operator+(const year_month_day_last& __ymdl, const months& __dm) noexcept;

  constexpr year_month_day_last
  operator-(const year_month_day_last& __ymdl, const months& __dm) noexcept;

  constexpr year_month_day_last
  operator+(const year_month_day_last& __ymdl, const years& __y) noexcept;

  constexpr year_month_day_last
  operator-(const year_month_day_last& __ymdl, const years& __y) noexcept;

  constexpr year_month_weekday_last
  operator+(const year_month_weekday_last& __ymwdl,
	    const months& __dm) noexcept;
  constexpr year_month_weekday_last
  operator+(const months& __dm,
	    const year_month_weekday_last& __ymwdl) noexcept;
  constexpr year_month_weekday_last
  operator+(const year_month_weekday_last& __ymwdl,
	    const years& __dy) noexcept;
  constexpr year_month_weekday_last
  operator+(const years& __dy,
	    const year_month_weekday_last& __ymwdl) noexcept;
  constexpr year_month_weekday_last
  operator-(const year_month_weekday_last& __ymwdl,
	    const months& __dm) noexcept;
  constexpr year_month_weekday_last
  operator-(const year_month_weekday_last& __ymwdl,
	    const years& __dy) noexcept;

  // CLOCKS

  class utc_clock
  {
  public:

    using duration = system_clock::duration;
    using rep = duration::rep;
    using period = duration::period;
    using time_point = chrono::time_point<utc_clock>;
    static constexpr bool is_steady = false;

    static time_point
    now();

    template<typename _Duration>
      static chrono::time_point<system_clock, common_type_t<_Duration, seconds>>
      to_sys(const chrono::time_point<utc_clock, _Duration>& __t);

    template<typename _Duration>
      static chrono::time_point<utc_clock, common_type_t<_Duration, seconds>>
      from_sys(const chrono::time_point<system_clock, _Duration>& __t);
  };

  class tai_clock
  {
  public:

    using duration = system_clock::duration;
    using rep = duration::rep;
    using period = duration::period;
    using time_point = chrono::time_point<tai_clock>;
    static constexpr bool is_steady = false;

    static time_point
    now();

    template<typename _Duration>
      static chrono::time_point<utc_clock, common_type_t<_Duration, seconds>>
      to_utc(const chrono::time_point<tai_clock, _Duration>&) noexcept;

    template<typename _Duration>
      static chrono::time_point<tai_clock, common_type_t<_Duration, seconds>>
      from_utc(const chrono::time_point<utc_clock, _Duration>&) noexcept;
  };

  class gps_clock
  {
  public:

    using duration = system_clock::duration;
    using rep = duration::rep;
    using period = duration::period;
    using time_point = chrono::time_point<gps_clock>;
    static constexpr bool is_steady = false;

    static time_point
    now();

    template<typename _Duration>
      static chrono::time_point<utc_clock, common_type_t<_Duration, seconds>>
      to_utc(const chrono::time_point<gps_clock, _Duration>&) noexcept;

    template<typename _Duration>
      static chrono::time_point<gps_clock, common_type_t<_Duration, seconds>>
      from_utc(const chrono::time_point<utc_clock, _Duration>&) noexcept;
  };

  class file_clock
  {
  public:

    using duration = system_clock::duration;
    using rep = duration::rep;
    using period = duration::period;
    using time_point = chrono::time_point<file_clock>;
    static constexpr bool is_steady = false;

    static time_point
    now() noexcept;

    // Conversion functions, see below
  };

  // TIME_POINT FAMILIES

  template<typename _Duration>
    using sys_time = time_point<system_clock, _Duration>;
  using sys_seconds = sys_time<seconds>;
  using sys_days = sys_time<days>;

  struct local_t {};
  template<typename _Duration>
    using local_time = time_point<local_t, _Duration>;
  using local_seconds = local_time<seconds>;
  using local_days = local_time<days>;

  template<typename _Duration>
    using utc_time = time_point<utc_clock, _Duration>;
  using utc_seconds = utc_time<seconds>;

  template<typename _Duration>
    using tai_time = time_point<tai_clock, _Duration>;
  using tai_seconds = tai_time<seconds>;

  template<typename _Duration>
    using gps_time = time_point<gps_clock, _Duration>;
  using gps_seconds = gps_time<seconds>;

  template<typename _Duration>
    using file_time = time_point<file_clock, _Duration>;

  // TIME_POINT CONVERSIONS

  template<typename _DestClock, typename _SourceClock>
    struct clock_time_conversion;

  //template<typename _DestClock, typename _SourceClock, typename _Duration>
  //  time_point<_DestClock, see below>
  //  clock_cast(const time_point<_SourceClock, _Duration>& __t);

  // Identity
  template<typename _Clock>
    struct clock_time_conversion<_Clock, _Clock>
    {
      template<typename _Duration>
	time_point<_Clock, _Duration>
	operator()(const time_point<_Clock, _Duration>& __t) const
	{ return __t; }
    };

  template<>
    struct clock_time_conversion<system_clock, system_clock>
    {
      template<typename _Duration>
	sys_time<_Duration>
	operator()(const sys_time<_Duration>& __t) const
	{ return __t; }
    };

  template<>
    struct clock_time_conversion<utc_clock, utc_clock>
    {
      template<typename _Duration>
	utc_time<_Duration>
	operator()(const utc_time<_Duration>& __t) const
	{ return __t; }
    };

  // system_clock <-> utc_clock
  template<>
    struct clock_time_conversion<utc_clock, system_clock>
    {
      template<typename _Duration>
	utc_time<common_type_t<_Duration, seconds>>
	operator()(const sys_time<_Duration>& __t) const
	{ return utc_clock::from_sys(__t); }
    };

  template<>
    struct clock_time_conversion<system_clock, utc_clock>
    {
      template<typename _Duration>
	sys_time<common_type_t<_Duration, seconds>>
	operator()(const utc_time<_Duration>& __t) const
	{ return utc_clock::to_sys(__t); }
    };

  // Clock <-> system_clock
  template<typename _SourceClock>
    struct clock_time_conversion<system_clock, _SourceClock>
    {
      template<typename _Duration>
	auto
	operator()(const time_point<_SourceClock, _Duration>& __t) const
	-> decltype(_SourceClock::to_sys(__t))
	{ return _SourceClock::to_sys(__t); }
    };
     

  template<typename _DestClock>
    struct clock_time_conversion<_DestClock, system_clock>
    {
      template<typename _Duration>
	auto
	operator()(const sys_time<_Duration>& __t) const
	-> decltype(_DestClock::from_sys(__t))
	{ return _DestClock::from_sys(__t); }
    };

  // Clock <-> utc_clock
  template<typename _SourceClock>
    struct clock_time_conversion<utc_clock, _SourceClock>
    {
      template<typename _Duration>
	auto
	operator()(const time_point<_SourceClock, _Duration>& __t) const
	-> decltype(_SourceClock::to_utc(__t))
	{ return _SourceClock::to_utc(__t); }
   };

  template<typename _DestClock>
    struct clock_time_conversion<_DestClock, utc_clock>
    {
      template<typename _Duration>
	auto
	operator()(const utc_time<_Duration>& __t) const
	-> decltype(_DestClock::from_utc(__t))
	{ return _DestClock::from_utc(__t); }
    };

  // TIME_POINT I/O

  // OPERATOR<<

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const sys_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const local_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const sys_days& __dp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const utc_time<_Duration>& __t);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const tai_time<_Duration>& __t);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const gps_time<_Duration>& __t);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const file_time<_Duration>& __tp);

  // TO_STREAM

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const sys_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const local_time<_Duration>& __tp,
	      const string* __abbrev = nullptr,
	      const seconds* __offset_sec = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const utc_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const tai_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const gps_time<_Duration>& __tp);

  template<typename _CharT, typename _Traits, typename _Duration>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const file_time<_Duration>& __tp);

  // FROM_STREAM

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		sys_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		local_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		utc_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		tai_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		gps_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		file_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // CALENDRICAL TYPES

  struct last_spec;

  // DAY

  class day
  {
  private:

    unsigned char _M_d;

  public:

    day() = default;

    explicit constexpr day(unsigned __d) noexcept
    : _M_d(__d)
    { }

    constexpr day&
    operator++() noexcept
    {
      ++this->_M_d;
      return *this;
    }

    constexpr day
    operator++(int) noexcept
    {
      auto ret(*this);
      ++this->_M_d;
      return ret;
    }

    constexpr day&
    operator--() noexcept
    {
      --this->_M_d;
      return *this;
    }

    constexpr day
    operator--(int) noexcept
    {
      auto ret(*this);
      --this->_M_d;
      return ret;
    }

    constexpr day&
    operator+=(const days& __d) noexcept
    {
      this->_M_d += __d.count();
      return *this;
    }

    constexpr day&
    operator-=(const days& __d) noexcept
    {
      this->_M_d -= __d.count();
      return *this;
    }

    constexpr explicit
    operator unsigned() const noexcept
    { return this->_M_d; }

    constexpr bool
    ok() const noexcept
    { return 1 <= this->_M_d && this->_M_d <= 31; }
  };

  constexpr bool
  operator==(const day& __x, const day& __y) noexcept
  { return unsigned{__x} == unsigned{__y}; }

  constexpr bool
  operator!=(const day& __x, const day& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const day& __x, const day& __y) noexcept
  { return unsigned{__x} < unsigned{__y}; }

  constexpr bool
  operator>(const day& __x, const day& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const day& __x, const day& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const day& __x, const day& __y) noexcept
  { return !(__x < __y); }

  constexpr day
  operator+(const day& __x, const days& __y) noexcept
  { return day(unsigned{__x} + __y.count()); }

  constexpr day
  operator+(const days& __x, const day& __y) noexcept
  { return __y + __x; }

  constexpr day
  operator-(const day& __x, const days& __y) noexcept
  { return __x + -__y; }

  constexpr days
  operator-(const day& __x, const day& __y) noexcept
  { return days{int(unsigned{__x}) - int(unsigned{__y})}; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const day& __d);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const day& __d);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		day& __d,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // MONTH

  class month
  {
  private:

    unsigned char _M_m;

  public:

    month() = default;

    explicit constexpr
    month(unsigned __m) noexcept
    : _M_m(__m)
    { }

    constexpr month&
    operator++() noexcept
    {
      ++this->_M_m;
      return *this;
    }

    constexpr month
    operator++(int) noexcept
    {
      auto ret(*this);
      ++this->_M_m;
      return ret;
    }

    constexpr month&
    operator--() noexcept
    {
      --this->_M_m;
      return *this;
    }

    constexpr month
    operator--(int) noexcept
    {
      auto ret(*this);
      --this->_M_m;
      return ret;
    }

    constexpr month&
    operator+=(const months& __m) noexcept
    {
      this->_M_m += __m.count();
      return *this;
    }

    constexpr month&
    operator-=(const months& __m) noexcept
    {
      this->_M_m -= __m.count();
      return *this;
    }

    explicit constexpr
    operator unsigned() const noexcept
    { return this->_M_m; }

    constexpr bool ok() const noexcept
    { return 1 <= this->_M_m && this->_M_m <= 12; }
  };

  constexpr bool
  operator==(const month& __x, const month& __y) noexcept
  { return unsigned{__x} == unsigned{__y}; }

  constexpr bool
  operator!=(const month& __x, const month& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const month& __x, const month& __y) noexcept
  { return unsigned{__x} < unsigned{__y}; }

  constexpr bool
  operator>(const month& __x, const month& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const month& __x, const month& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const month& __x, const month& __y) noexcept
  { return !(__x < __y); }

  constexpr month
  operator+(const month& __x, const months& __y) noexcept
  { return month(modulo<unsigned char>(static_cast<long long>(unsigned{__x}) + (__y.count() - 1), 12) + 1); }

  constexpr month
  operator+(const months& __x,  const month& __y) noexcept
  { return __y + __x; }

  constexpr month
  operator-(const month& __x, const months& __y) noexcept
  { return __x + -__y; }

  constexpr months
  operator-(const month& __x,  const month& __y) noexcept
  { return /*FIXME*/months{0}; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const month& __m);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month& __m);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month& __m,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // YEAR

  class year
  {
    short _M_y;

  public:

    year() = default;

    explicit constexpr
    year(int __y) noexcept;

    static constexpr year
    min() noexcept
    { return year{-32767}; }

    static constexpr year
    max() noexcept
    { return year{32767}; }

    constexpr year&
    operator++() noexcept
    {
      ++this->_M_y;
      return *this;
    }

    constexpr year
    operator++(int) noexcept
    {
      auto ret(*this);
      ++this->_M_y;
      return ret;
    }

    constexpr year&
    operator--() noexcept
    {
      --this->_M_y;
      return *this;
    }

    constexpr year
    operator--(int) noexcept
    {
      auto ret(*this);
      --this->_M_y;
      return ret;
    }

    constexpr year&
    operator+=(const years& __y) noexcept
    {
      this->_M_y += __y.count();
      return *this;
    }

    constexpr year&
    operator-=(const years& __y) noexcept
    {
      this->_M_y -= __y.count();
      return *this;
    }

    constexpr year
    operator+() const noexcept
    { return *this; }

    constexpr year
    operator-() const noexcept
    { return year(-this->_M_y); }

    constexpr bool
    is_leap() const noexcept
    {
      return this->_M_y % 4 == 0
	  && (this->_M_y % 100 != 0 || this->_M_y % 400 == 0);
    }

    explicit constexpr
    operator int() const noexcept
    { return this->_M_y; }

    constexpr bool
    ok() const noexcept
    { return int(year::min()) <= this->_M_y && this->_M_y <= int(year::max()); }
  };

  constexpr bool
  operator==(const year& __x, const year& __y) noexcept
  { return int{__x} == int{__y}; }

  constexpr bool
  operator!=(const year& __x, const year& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const year& __x, const year& __y) noexcept
  { return int{__x} < int{__y}; }

  constexpr bool
  operator>(const year& __x, const year& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const year& __x, const year& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const year& __x, const year& __y) noexcept
  { return !(__x < __y); }

  constexpr year
  operator+(const year&x, const years& __y) noexcept;

  constexpr year
  operator+(const years& __x, const year& __y) noexcept;

  constexpr year
  operator-(const year& __x, const years& __y) noexcept;

  constexpr years
  operator-(const year& __x, const year& __y) noexcept;

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const year& __y);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year& __y);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year& __y,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // WEEKDAY

  class weekday
  {
  private:

    unsigned char _M_wd;

    constexpr static unsigned char
    __from_days(int __d) noexcept
    {
      return static_cast<unsigned char>(
        unsigned(__d >= -4 ? (__d + 4) % 7 : (__d + 5) % 7 + 6));
    }

  public:

    weekday() = default;

    explicit constexpr
    weekday(unsigned __wd) noexcept
    : _M_wd(__wd == 7 ? 0 : __wd) // __wd % 7 ?
    { }

    constexpr
    weekday(const sys_days& __dp) noexcept
    : _M_wd(__from_days(__dp.time_since_epoch().count()))
    { }

    explicit constexpr
    weekday(const local_days& __dp) noexcept
    : _M_wd(__from_days(__dp.time_since_epoch().count()))
    { }

    constexpr weekday&
    operator++() noexcept
    {
      ++this->_M_wd;
      return *this;
    }

    constexpr weekday
    operator++(int) noexcept
    {
      auto __ret(*this);
      ++(*this);
      return __ret;
    }

    constexpr weekday&
    operator--() noexcept
    {
      --this->_M_wd;
      return *this;
    }

    constexpr weekday
    operator--(int) noexcept
    {
      auto __ret(*this);
      --(*this);
      return __ret;
    }

    constexpr weekday&
    operator+=(const days& __d) noexcept
    {
      *this += __d;
      return *this;
    }

    constexpr weekday&
    operator-=(const days& __d) noexcept
    {
      *this -= __d;
      return *this;
    }

    explicit constexpr
    operator unsigned() const noexcept
    { return this->_M_wd; }

    constexpr bool
    ok() const noexcept
    { return this->_M_wd <= 6; }

    constexpr weekday_indexed
    operator[](unsigned __index) const noexcept;

    constexpr weekday_last
    operator[](last_spec) const noexcept;
  };

  constexpr bool
  operator==(const weekday& __x, const weekday& __y) noexcept
  { return unsigned{__x} == unsigned{__y}; }

  constexpr bool
  operator!=(const weekday& __x, const weekday& __y) noexcept
  { return !(__x == __y); }

  constexpr weekday
  operator+(const weekday& __x, const days& __y) noexcept
  { return weekday(modulo<unsigned char>(static_cast<long long>(unsigned{__x}) + __y.count(), 7)); }

  constexpr weekday
  operator+(const days& __x, const weekday& __y) noexcept
  { return __y + __x; }

  constexpr weekday
  operator-(const weekday& __x, const days& __y) noexcept
  { return __x + -__y; }

  constexpr days
  operator-(const weekday& __x, const weekday& __y) noexcept
  {
    const auto __dwd = int(unsigned(__x)) - int(unsigned(__y));
    const auto __w = (__dwd >= 0 ? __dwd : __dwd - 6) / 7;
    return days{__dwd - __w * 7};
  }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const weekday& __wd);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const weekday& __wd);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		weekday& __wd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // WEEKDAY_INDEXED

  class weekday_indexed
  {
  private:

    chrono::weekday _M_wd;
    unsigned char _M_index;

  public:

    weekday_indexed() = default;

    constexpr
    weekday_indexed(const chrono::weekday& __wd, unsigned __index) noexcept
    : _M_wd(__wd), _M_index(__index)
    { }

    constexpr chrono::weekday
    weekday() const noexcept
    { return this->_M_wd; }

    constexpr unsigned
    index() const noexcept
    { return this->_M_index; };

    constexpr bool
    ok() const noexcept
    { return _M_wd.ok() && 1 <= this->_M_index && this->_M_index <= 5; }
  };

  constexpr bool
  operator==(const weekday_indexed& __x, const weekday_indexed& __y) noexcept
  { return __x.weekday() == __y.weekday() && __x.index() == __y.index(); }

  constexpr bool
  operator!=(const weekday_indexed& __x, const weekday_indexed& __y) noexcept
  { return !(__x == __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const weekday_indexed& __wdi);

  inline constexpr weekday_indexed
  weekday::operator[](unsigned __index) const noexcept
  { return {*this, __index}; }

  // WEEKDAY_LAST

  class weekday_last
  {
  private:

    chrono::weekday _M_wd;

  public:

    explicit constexpr
    weekday_last(const chrono::weekday& __wd) noexcept
    : _M_wd{__wd}
    { }

    constexpr chrono::weekday
    weekday() const noexcept
    { return this->_M_wd; }

    constexpr bool
    ok() const noexcept
    { return this->_M_wd.ok(); }
  };

  constexpr bool
  operator==(const weekday_last& __x, const weekday_last& __y) noexcept
  { return __x.weekday() == __y.weekday(); }

  constexpr bool
  operator!=(const weekday_last& __x, const weekday_last& __y) noexcept
  { return !(__x == __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const weekday_last& __wdl);

  inline constexpr weekday_last
  weekday::operator[](last_spec) const noexcept
  { return weekday_last{*this}; }

  // MONTH_DAY

  class month_day
  {
    chrono::month _M_m;
    chrono::day _M_d;

  public:

    month_day() = default;
    constexpr
    month_day(const chrono::month& __m, const chrono::day& __d) noexcept;

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::day
    day() const noexcept
    { return this->_M_d; }

    constexpr bool
    ok() const noexcept
    {
      return 1u <= unsigned(this->_M_d)
	&& this->_M_m.ok()
	&& unsigned(this->_M_d)
	   <= __detail::__days_per_month[unsigned(this->_M_m) - 1];
    }
  };

  constexpr bool
  operator==(const month_day& __x, const month_day& __y) noexcept
  { return __x.month() == __y.month() && __x.day() == __y.day(); }

  constexpr bool
  operator!=(const month_day& __x, const month_day& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const month_day& __x, const month_day& __y) noexcept
  {
    if (__x.month() < __y.month())
      return true;
    else if (__x.month() > __y.month())
      return false;
    else
      return __x.day() < __y.day();
  }

  constexpr bool
  operator>(const month_day& __x, const month_day& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const month_day& __x, const month_day& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const month_day& __x, const month_day& __y) noexcept
  { return !(__x < __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const month_day& __md);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month_day& __md);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month_day& __md,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // MONTH_DAY_LAST

  class month_day_last
  {
  private:

    chrono::month _M_m;

  public:

    explicit constexpr
    month_day_last(const chrono::month& __m) noexcept;

    constexpr chrono::month
    month() const noexcept;

    constexpr bool
    ok() const noexcept;
  };

  constexpr bool
  operator==(const month_day_last& __x, const month_day_last& __y) noexcept
  { return __x.month() == __y.month(); }

  constexpr bool
  operator!=(const month_day_last& __x, const month_day_last& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const month_day_last& __x, const month_day_last& __y) noexcept
  { return __x.month() < __y.month(); }

  constexpr bool
  operator>(const month_day_last& __x, const month_day_last& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const month_day_last& __x, const month_day_last& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const month_day_last& __x, const month_day_last& __y) noexcept
  { return !(__x < __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_day_last& __mdl);

  // MONTH_WEEKDAY

  class month_weekday
  {
  private:

    chrono::month _M_m;
    chrono::weekday_indexed _M_wdi;

  public:

    constexpr
    month_weekday(const chrono::month& __m,
		  const chrono::weekday_indexed& __wdi) noexcept;

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::weekday_indexed
    weekday_indexed() const noexcept
    { return this->_M_wdi; }

    constexpr bool
    ok() const noexcept
    { return this->_M_m.ok() && this->_M_wdi.ok(); }
  };

  constexpr bool
  operator==(const month_weekday& __x, const month_weekday& __y) noexcept
  {
    return __x.month() == __y.month()
	&& __x.weekday_indexed() == __y.weekday_indexed();
  }

  constexpr bool
  operator!=(const month_weekday& __x, const month_weekday& __y) noexcept
  { return !(__x == __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday& __mwd);

  // MONTH_WEEKDAY_LAST

  class month_weekday_last
  {
  private:

    chrono::month _M_m;
    chrono::weekday_last _M_wdl;

  public:

    constexpr
    month_weekday_last(const chrono::month& __m,
                       const chrono::weekday_last& __wdl) noexcept
    :_M_m{__m}, _M_wdl{__wdl}
    { }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::weekday_last
    weekday_last() const noexcept
    { return this->_M_wdl; }

    constexpr bool
    ok() const noexcept
    { return this->_M_m.ok() && this->_M_wdl.ok(); }
  };

  constexpr bool
  operator==(const month_weekday_last& __x,
	     const month_weekday_last& __y) noexcept
  {
    return __x.month() == __y.month()
	&& __x.weekday_last() == __y.weekday_last();
  }

  constexpr bool
  operator!=(const month_weekday_last& __x,
	     const month_weekday_last& __y) noexcept
  { return !(__x == __y); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday_last& __mwdl);

  // YEAR_MONTH

  class year_month
  {
  private:

    chrono::year _M_y;
    chrono::month _M_m;

  public:

    year_month() = default;

    constexpr
    year_month(const chrono::year& __y, const chrono::month& __m) noexcept
    : _M_y{__y}, _M_m{__m}
    { }

    constexpr chrono::year
    year() const noexcept
    { return this->_M_y; }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr year_month&
    operator+=(const months& __dm) noexcept
    {
      // Does this work for negative dm?
      this->_M_y += years{__dm.count() / 12};
      this->_M_m += months{__dm.count() % 12};
      return *this;
    }

    constexpr year_month&
    operator-=(const months& __dm) noexcept
    {
      this->operator+=(-__dm);
      return *this;
    }

    constexpr year_month&
    operator+=(const years& __dy)  noexcept
    {
      this->_M_y += __dy;
      return *this;
    }

    constexpr year_month&
    operator-=(const years& __dy)  noexcept
    {
      this->_M_y -= __dy;
      return *this;
    }

    constexpr bool
    ok() const noexcept
    { return this->_M_y.ok() && this->_M_y.ok(); }
  };

  constexpr bool
  operator==(const year_month& __x, const year_month& __y) noexcept
  { return __x.year() == __y.year() && __x.month() == __y.month(); }

  constexpr bool
  operator!=(const year_month& __x, const year_month& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const year_month& __x, const year_month& __y) noexcept
  {
    if (__x.year() < __y.year())
      return true;
    else if (__x.year() > __y.year())
      return false;
    else
      return __x.month() < __y.month();
  }

  constexpr bool
  operator>(const year_month& __x, const year_month& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const year_month& __x, const year_month& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const year_month& __x, const year_month& __y) noexcept
  { return !(__x < __y); }

  constexpr year_month
  operator+(const year_month& __ym, const months& __dm) noexcept
  {
    auto __ret = __ym;
    return __ret += __dm;
  }

  constexpr year_month
  operator+(const months& __dm, const year_month& __ym) noexcept
  { return __ym + __dm; }

  constexpr year_month
  operator-(const year_month& __ym, const months& __dm) noexcept
  { return __ym + -__dm; }

  constexpr months
  operator-(const year_month& __x, const year_month& __y) noexcept
  {
    return __x.year() - __y.year()
	 + months{static_cast<int>(unsigned{__x.month()})
		- static_cast<int>(unsigned{__y.month()})};
  }

  constexpr year_month
  operator+(const year_month& __ym, const years& __dy) noexcept
  { return (__ym.year() + __dy) / __ym.month(); }

  constexpr year_month
  operator+(const years& __dy, const year_month& __ym) noexcept
  { return __ym + __dy; }

  constexpr year_month
  operator-(const year_month& __ym, const years& __dy) noexcept
  { return __ym + -__dy; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month& __ym);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month& __ym);

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month& __ym,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // YEAR_MONTH_DAY

  class year_month_day
  {
  private:

    chrono::year _M_y;
    chrono::month _M_m;
    chrono::day _M_d;

    // Magic.
    constexpr static year_month_day
    __from_days(const days& __dp) noexcept
    {
      const auto __z = __dp.count() + 719468;
      const auto __era = (__z >= 0 ? __z : __z - 146096) / 146097;
      const auto __doe = static_cast<unsigned>(__z - __era * 146097);
      const auto __yoe = (__doe - __doe / 1460 + __doe / 36524 - __doe / 146096)
			/ 365;
      const auto __y = static_cast<days::rep>(__yoe) + __era * 400;
      const auto __doy = __doe - (365 * __yoe + __yoe / 4 - __yoe / 100);
      const auto __mp = (5 * __doy + 2) / 153;
      const auto __d = __doy - (153 * __mp + 2) / 5 + 1;
      const auto __m = __mp < 10 ? __mp + 3 : __mp - 9;
      return year_month_day{chrono::year(__y + (__m <= 2)),
			    chrono::month(__m), chrono::day(__d)};
    }

  public:

    year_month_day() = default;

    constexpr
    year_month_day(const chrono::year& __y, const chrono::month& __m,
		   const chrono::day& __d) noexcept
    : _M_y{__y}, _M_m{__m}, _M_d{__d}
    { }

    constexpr
    year_month_day(const year_month_day_last& __ymdl) noexcept;

    constexpr
    year_month_day(const sys_days& __dp) noexcept
    : year_month_day(__from_days(__dp.time_since_epoch()))
    { }

    explicit constexpr
    year_month_day(const local_days& __dp) noexcept
    : year_month_day(__from_days(__dp.time_since_epoch()))
    { }

    constexpr year_month_day&
    operator+=(const months& __m) noexcept
    {
      chrono::year_month __ym(this->year(), this->month());
      __ym += __m;
      this->_M_y = __ym.year();
      this->_M_m = __ym.month();
      return *this;
    }

    constexpr year_month_day&
    operator-=(const months& __m) noexcept
    {
      chrono::year_month __ym(this->year(), this->month());
      __ym -= __m;
      this->_M_y = __ym.year();
      this->_M_m = __ym.month();
      return *this;
    }

    constexpr year_month_day&
    operator+=(const years& __y) noexcept
    {
      this->_M_y += __y;
      return *this;
    }

    constexpr year_month_day&
    operator-=(const years& __y) noexcept
    {
      this->_M_y -= __y;
      return *this;
    }

    constexpr chrono::year
    year() const noexcept
    { return this->_M_y; }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::day
    day() const noexcept
    { return this->_M_d; }

    constexpr
    operator sys_days() const noexcept;

    explicit constexpr
    operator local_days() const noexcept
    { return local_days{sys_days{*this}.time_since_epoch()}; }

    constexpr bool
    ok() const noexcept
    { return this->_M_y.ok() && this->_M_y.ok() && this->_M_d.ok(); }
  };

  constexpr bool
  operator==(const year_month_day& __x, const year_month_day& __y) noexcept
  {
    return __x.year() == __y.year()
	&& __x.month() == __y.month()
	&& __x.day() == __y.day();
  }

  constexpr bool
  operator!=(const year_month_day& __x, const year_month_day& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const year_month_day& __x, const year_month_day& __y) noexcept
  {
    if (__x.year() < __y.year())
      return true;
    else if (__x.year() > __y.year())
      return false;
    else
      {
	if (__x.month() < __y.month())
	  return true;
	else if (__x.month() > __y.month())
	  return false;
	else
	  return __x.day() < __y.day();
      }
  }

  constexpr bool
  operator>(const year_month_day& __x, const year_month_day& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const year_month_day& __x, const year_month_day& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const year_month_day& __x, const year_month_day& __y) noexcept
  { return !(__x < __y); }

  constexpr year_month_day
  operator+(const year_month_day& __ymd, const months& __dm) noexcept
  { return (__ymd.year() / __ymd.month() + __dm) / __ymd.day(); }

  constexpr year_month_day
  operator+(const months& __dm, const year_month_day& __ymd) noexcept
  { return __ymd + __dm; }

  constexpr year_month_day
  operator+(const year_month_day& __ymd, const years& __dy) noexcept
  { return (__ymd.year() + __dy) / __ymd.month() / __ymd.day(); }

  constexpr year_month_day
  operator+(const years& __dy, const year_month_day& __ymd) noexcept
  { return __ymd + __dy; }

  constexpr year_month_day
  operator-(const year_month_day& __ymd, const months& __dm) noexcept
  { return __ymd + -__dm; }

  constexpr year_month_day
  operator-(const year_month_day& __ymd, const years& __dy) noexcept
  { return __ymd + -__dy; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day& __ymd);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month_day& __ymd);

  template<typename _CharT, typename _Traits, typename _Alloc = allocator<_CharT>>
    basic_istream<_CharT, _Traits>&
    from_stream(basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month_day& __ymd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev = nullptr,
		minutes* __offset = nullptr);

  // YEAR_MONTH_DAY_LAST

  class year_month_day_last
  {
  private:

    chrono::year _M_y;
    chrono::month_day_last _M_mdl;

  public:

    constexpr
    year_month_day_last(const chrono::year& __y,
                        const chrono::month_day_last& __mdl) noexcept
    : _M_y{__y}, _M_mdl{__mdl}
    { }

    constexpr year_month_day_last&
    operator+=(const months& __m) noexcept
    {
      *this = *this + __m;
      return *this;
    }

    constexpr year_month_day_last&
    operator-=(const months& __m) noexcept
    {
      *this = *this - __m;
      return *this;
    }

    constexpr year_month_day_last&
    operator+=(const years& __y)  noexcept
    {
      *this = *this + __y;
      return *this;
    }

    constexpr year_month_day_last&
    operator-=(const years& __y)  noexcept
    {
      *this = *this - __y;
      return *this;
    }

    constexpr chrono::year
    year() const noexcept
    { return this->_M_y; }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_mdl.month(); }

    constexpr chrono::month_day_last
    month_day_last() const noexcept
    { return this->_M_mdl; }

    // Return A day representing the last day of this year, month pair.
    constexpr chrono::day
    day() const noexcept
    {
      return this->month() != chrono::month{2}
	  || !this->_M_y.is_leap()
	   ? chrono::day{__detail::__last_day[unsigned(this->_M_mdl.month()) - 1]}
	   : chrono::day{29};
    }

    constexpr
    operator sys_days() const noexcept
    { sys_days{this->year() / this->month() / this->day()}; }

    explicit constexpr
    operator local_days() const noexcept
    { return local_days{sys_days{*this}.time_since_epoch()}; }

    constexpr bool
    ok() const noexcept
    { return this->_M_y.ok() && this->_M_mdl.ok(); }
  };

  // year_month_day ctor from year_month_day_last
  inline constexpr
  year_month_day::year_month_day(const year_month_day_last& __ymdl) noexcept
  : _M_y{__ymdl.year()}, _M_m{__ymdl.month()}, _M_d{__ymdl.day()}
  { }

  constexpr bool
  operator==(const year_month_day_last& __x,
	     const year_month_day_last& __y) noexcept
  {
    return __x.year() == __y.year()
	&& __x.month_day_last() == __y.month_day_last();
  }

  constexpr bool
  operator!=(const year_month_day_last& __x,
	     const year_month_day_last& __y) noexcept
  { return !(__x == __y); }

  constexpr bool
  operator<(const year_month_day_last& __x,
	    const year_month_day_last& __y) noexcept
  {
    if (__x.year() < __y.year())
      return true;
    else if (__x.year() > __y.year())
      return false;
    else
      return __x.month_day_last() < __y.month_day_last();
  }

  constexpr bool
  operator>(const year_month_day_last& __x,
	    const year_month_day_last& __y) noexcept
  { return __y < __x; }

  constexpr bool
  operator<=(const year_month_day_last& __x,
	     const year_month_day_last& __y) noexcept
  { return !(__y < __x); }

  constexpr bool
  operator>=(const year_month_day_last& __x,
	     const year_month_day_last& __y) noexcept
  { return !(__x < __y); }

  constexpr year_month_day_last
  operator+(const year_month_day_last& __ymdl,
	    const months& __dm) noexcept
  { return (__ymdl.year() / __ymdl.month() + __dm) / last; }

  constexpr year_month_day_last
  operator+(const months& __dm,
	    const year_month_day_last& __ymdl) noexcept
  { return __ymdl + __dm; }

  constexpr year_month_day_last
  operator-(const year_month_day_last& __ymdl,
	    const months& __dm) noexcept
  { return __ymdl + -__dm; }

  constexpr year_month_day_last
  operator+(const year_month_day_last& __ymdl,
	    const years& __dy) noexcept
  { return {__ymdl.year() + __dy, __ymdl.month_day_last()}; }

  constexpr year_month_day_last
  operator+(const years& __dy,
	    const year_month_day_last& __ymdl) noexcept
  { return __ymdl + __dy; }

  constexpr year_month_day_last
  operator-(const year_month_day_last& __ymdl,
	    const years& __dy) noexcept
  { return __ymdl + -__dy; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day_last& __ymdl);

  // YEAR_MONTH_WEEKDAY

  class year_month_weekday
  {
  private:

    chrono::year            _M_y;
    chrono::month           _M_m;
    chrono::weekday_indexed _M_wdi;

  public:

    year_month_weekday() = default;

    constexpr
    year_month_weekday(const chrono::year& __y, const chrono::month& __m,
                       const chrono::weekday_indexed& __wdi) noexcept;

    constexpr
    year_month_weekday(const sys_days& __dp) noexcept;

    explicit constexpr
    year_month_weekday(const local_days& __dp) noexcept;

    constexpr year_month_weekday&
    operator+=(const months& __m) noexcept;

    constexpr year_month_weekday&
    operator-=(const months& __m) noexcept;

    constexpr year_month_weekday&
    operator+=(const years& __y) noexcept;

    constexpr year_month_weekday&
    operator-=(const years& y) noexcept;

    constexpr chrono::year
    year() const noexcept
    { return this->_M_y; }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::weekday
    weekday() const noexcept
    { return this->_M_wdi.weekday(); }

    constexpr unsigned
    index() const noexcept
    { return this->_M_wdi.index(); }

    constexpr chrono::weekday_indexed
    weekday_indexed() const noexcept
    { return this->_M_wdi; }

    constexpr
    operator sys_days() const noexcept;

    explicit constexpr
    operator local_days() const noexcept
    { local_days{sys_days{*this}.time_since_epoch()}; }

    constexpr bool
    ok() const noexcept
    { return this->_M_y.ok() && this->_M_m.ok() && this->_M_wdi.ok(); }
  };

  constexpr bool
  operator==(const year_month_weekday& __x,
	     const year_month_weekday& __y) noexcept
  {
    return __x.year() == __y.year()
	&& __x.month() == __y.month()
	&& __x.weekday() == __y.weekday();
  }

  constexpr bool
  operator!=(const year_month_weekday& __x,
	     const year_month_weekday& __y) noexcept
  { return !(__x == __y); }

  constexpr year_month_weekday
  operator+(const year_month_weekday& __ymwd, const months& __dm) noexcept
  { return (__ymwd.year() / __ymwd.month() + __dm) / __ymwd.weekday_indexed(); }

  constexpr year_month_weekday
  operator+(const months& __dm, const year_month_weekday& __ymwd) noexcept
  { return __ymwd + __dm; }

  constexpr year_month_weekday
  operator+(const year_month_weekday& __ymwd, const years& __dy) noexcept
  { return {__ymwd.year() + __dy, __ymwd.month(), __ymwd.weekday_indexed()}; }

  constexpr year_month_weekday
  operator+(const years& __dy, const year_month_weekday& __ymwd) noexcept
  { return __ymwd + __dy; }

  constexpr year_month_weekday
  operator-(const year_month_weekday& __ymwd, const months& __dm) noexcept
  { return __ymwd + -__dm; }

  constexpr year_month_weekday
  operator-(const year_month_weekday& __ymwd, const years& __dy) noexcept
  { return __ymwd + -__dy; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday& __ymwdi);

  // YEAR_MONTH_WEEKDAY_LAST

  class year_month_weekday_last
  {
  private:

    chrono::year _M_y;
    chrono::month _M_m;
    chrono::weekday_last _M_wdl;

  public:

    constexpr
    year_month_weekday_last(const chrono::year& __y, const chrono::month& __m,
                            const chrono::weekday_last& __wdl) noexcept
    : _M_y{__y}, _M_m{__m}, _M_wdl{__wdl}
    { }

    constexpr year_month_weekday_last&
    operator+=(const months& __m) noexcept
    {
      *this = *this + __m;
      return *this;
    }

    constexpr year_month_weekday_last&
    operator-=(const months& __m) noexcept
    {
      *this = *this - __m;
      return *this;
    }

    constexpr year_month_weekday_last&
    operator+=(const years& __y)  noexcept
    {
      *this = *this + __y;
      return *this;
    }

    constexpr year_month_weekday_last&
    operator-=(const years& __y)  noexcept
    {
      *this = *this - __y;
      return *this;
    }

    constexpr chrono::year
    year() const noexcept
    { return this->_M_y; }

    constexpr chrono::month
    month() const noexcept
    { return this->_M_m; }

    constexpr chrono::weekday
    weekday() const noexcept
    { return this->_M_wdl.weekday(); }

    constexpr chrono::weekday_last
    weekday_last() const noexcept
    { return this->_M_wdl; }

    constexpr
    operator sys_days() const noexcept
    { return sys_days{sys_days{*this}.time_since_epoch()}; }

    explicit constexpr
    operator local_days() const noexcept
    { return local_days{sys_days{*this}.time_since_epoch()}; }

    constexpr bool
    ok() const noexcept
    { return this->_M_y.ok() && this->_M_m.ok() && this->_M_wdl.ok(); }
  };

  constexpr bool
  operator==(const year_month_weekday_last& __x,
	     const year_month_weekday_last& __y) noexcept
  {
    return __x.year() == __y.year()
	&& __x.month() == __y.month()
	&& __x.weekday_last() == __y.weekday_last();
  }

  constexpr bool
  operator!=(const year_month_weekday_last& __x,
	     const year_month_weekday_last& __y) noexcept
  { return !(__x == __y); }

  constexpr year_month_weekday_last
  operator+(const year_month_weekday_last& __ymwdl,
	    const months& __dm) noexcept
  { return (__ymwdl.year() / __ymwdl.month() + __dm) / __ymwdl.weekday_last(); }

  constexpr year_month_weekday_last
  operator+(const months& __dm,
	    const year_month_weekday_last& __ymwdl) noexcept
  { return __ymwdl + __dm; }

  constexpr year_month_weekday_last
  operator+(const year_month_weekday_last& __ymwdl,
	    const years& __dy) noexcept
  { return {__ymwdl.year() + __dy, __ymwdl.month(), __ymwdl.weekday_last()}; }

  constexpr year_month_weekday_last
  operator+(const years& __dy,
	    const year_month_weekday_last& __ymwdl) noexcept
  { return __ymwdl + __dy; }

  constexpr year_month_weekday_last
  operator-(const year_month_weekday_last& __ymwdl,
	    const months& __dm) noexcept
  { return __ymwdl + -__dm; }

  constexpr year_month_weekday_last
  operator-(const year_month_weekday_last& __ymwdl,
	    const years& __dy) noexcept
  { return __ymwdl + -__dy; }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday_last& __ymwdl);

  // CALENDAR COMPOSITION OPERATORS

  constexpr year_month
  operator/(const year& __y, const month& __m) noexcept
  { return {__y, __m}; }

  constexpr year_month
  operator/(const year& __y, int __m) noexcept
  { return {__y, month(unsigned(__m))}; }

  constexpr month_day
  operator/(const month& __m, const day& __d) noexcept
  { return {__m, __d}; }

  constexpr month_day
  operator/(const month& __m, int __d) noexcept
  { return {__m, day(unsigned(__d))}; }

  constexpr month_day
  operator/(int __m, const day& __d) noexcept
  { return {month(unsigned(__m)), __d}; }

  constexpr month_day
  operator/(const day& __d, const month& __m) noexcept
  { return {__m, __d}; }

  constexpr month_day
  operator/(const day& __d, int __m) noexcept
  { return {month(unsigned(__m)), __d}; }

  constexpr month_day_last
  operator/(const month& __m, last_spec) noexcept
  { return month_day_last{__m}; }

  constexpr month_day_last
  operator/(int __m, last_spec) noexcept
  { return month(unsigned(__m)) / last; }

  constexpr month_day_last
  operator/(last_spec, const month& __m) noexcept
  { return __m / last; }

  constexpr month_day_last
  operator/(last_spec, int __m) noexcept
  { return __m / last; }

  constexpr month_weekday
  operator/(const month& __m, const weekday_indexed& __wdi) noexcept
  { return {__m, __wdi}; }

  constexpr month_weekday
  operator/(int __m, const weekday_indexed& __wdi) noexcept
  { return month(unsigned(__m)) / __wdi; }

  constexpr month_weekday
  operator/(const weekday_indexed& __wdi, const month& __m) noexcept
  { return __m / __wdi; }

  constexpr month_weekday
  operator/(const weekday_indexed& __wdi, int __m) noexcept
  { return __m / __wdi; }

  constexpr month_weekday_last
  operator/(const month& __m, const weekday_last& __wdl) noexcept
  { return {__m, __wdl}; }

  constexpr month_weekday_last
  operator/(int __m, const weekday_last& __wdl) noexcept
  { return month(unsigned(__m)) / __wdl; }

  constexpr month_weekday_last
  operator/(const weekday_last& __wdl, const month& __m) noexcept
  { return __m / __wdl; }

  constexpr month_weekday_last
  operator/(const weekday_last& __wdl, int __m) noexcept
  { return chrono::month(unsigned(__m)) / __wdl; }

  constexpr year_month_day
  operator/(const year_month& __ym, const day& __d) noexcept
  { return {__ym.year(), __ym.month(), __d}; }

  constexpr year_month_day
  operator/(const year_month& __ym, int __d) noexcept
  { return __ym / chrono::day{unsigned(__d)}; }

  constexpr year_month_day
  operator/(const year& __y, const month_day& __md) noexcept
  { return __y / __md; }

  constexpr year_month_day
  operator/(int __y, const month_day& __md) noexcept
  { return chrono::year{__y} / __md; }

  constexpr year_month_day
  operator/(const month_day& __md, const year& __y) noexcept
  { return __y / __md; }

  constexpr year_month_day
  operator/(const month_day& __md, int __y) noexcept
  { return year(__y) / __md; }

  constexpr year_month_day_last
  operator/(const year_month& __ym, last_spec) noexcept
  { return {__ym.year(), month_day_last{__ym.month()}}; }

  constexpr year_month_day_last
  operator/(const year& __y, const month_day_last& __mdl) noexcept
  { return {__y, __mdl}; }

  constexpr year_month_day_last
  operator/(int __y, const month_day_last& __mdl) noexcept
  { return year(__y) / __mdl; }

  constexpr year_month_day_last
  operator/(const month_day_last& __mdl, const year& __y) noexcept
  { return __y / __mdl; }

  constexpr year_month_day_last
  operator/(const month_day_last& __mdl, int __y) noexcept
  { return year(__y) / __mdl; }

  constexpr year_month_weekday
  operator/(const year_month& __ym, const weekday_indexed& __wdi) noexcept
  { return {__ym.year(), __ym.month(), __wdi}; }

  constexpr year_month_weekday
  operator/(const year& __y, const month_weekday& __mwd) noexcept
  { return {__y, __mwd.month(), __mwd.weekday_indexed()}; }

  constexpr year_month_weekday
  operator/(int __y, const month_weekday& __mwd) noexcept
  { return year(__y) / __mwd; }

  constexpr year_month_weekday
  operator/(const month_weekday& __mwd, const year& __y) noexcept
  { return __y / __mwd; }

  constexpr year_month_weekday
  operator/(const month_weekday& __mwd, int __y) noexcept
  { return year(__y) / __mwd; }

  constexpr year_month_weekday_last
  operator/(const year_month& __ym, const weekday_last& __wdl) noexcept
  { return {__ym.year(), __ym.month(), __wdl}; }

  constexpr year_month_weekday_last
  operator/(const year& __y, const month_weekday_last& __mwdl) noexcept
  { return {__y, __mwdl.month(), __mwdl.weekday_last()}; }

  constexpr year_month_weekday_last
  operator/(int __y, const month_weekday_last& __mwdl) noexcept
  { return year(__y) / __mwdl; }

  constexpr year_month_weekday_last
  operator/(const month_weekday_last& __mwdl, const year& __y) noexcept
  { __y / __mwdl; }

  constexpr year_month_weekday_last
  operator/(const month_weekday_last& __mwdl, int __y) noexcept
  { year(__y) / __mwdl; }

  // TIME_OF_DAY

  template<typename _Duration>
    class time_of_day;

  template<>
    class time_of_day<hours>
    {
    public:

      using precision = chrono::hours;

      time_of_day() = default;

      explicit constexpr
      time_of_day(chrono::hours __since_midnight) noexcept;

      constexpr chrono::hours
      hours() const noexcept;

      explicit constexpr
      operator precision() const noexcept;

      constexpr precision
      to_duration() const noexcept;

      constexpr void
      make24() noexcept;

      constexpr void
      make12() noexcept;
    };

  template<>
    class time_of_day<minutes>
    {
    public:

      using precision = chrono::minutes;

      time_of_day() = default;

      explicit constexpr
      time_of_day(chrono::minutes __since_midnight) noexcept;

      constexpr chrono::hours
      hours() const noexcept;

      constexpr chrono::minutes
      minutes() const noexcept;

      explicit constexpr
      operator precision() const noexcept;

      constexpr precision
      to_duration() const noexcept;

      constexpr void
      make24() noexcept;

      constexpr void
      make12() noexcept;
    };

  template<>
    class time_of_day<seconds>
    {
      public:

      using precision = chrono::seconds;

      time_of_day() = default;

      explicit constexpr
      time_of_day(chrono::seconds __since_midnight) noexcept;

      constexpr chrono::hours
      hours() const noexcept;

      constexpr chrono::minutes
      minutes() const noexcept;

      constexpr chrono::seconds
      seconds() const noexcept;

      explicit constexpr
      operator precision() const noexcept;

      constexpr precision
      to_duration() const noexcept;

      constexpr void
      make24() noexcept;

      constexpr void
      make12() noexcept;
    };

  template<typename _Rep, typename _Period>
    class time_of_day<duration<_Rep, _Period>>;

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<hours>& __t);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<minutes>& __t);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<seconds>& __t);

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<duration<_Rep, _Period>>& __t);

  // INFORMATION CLASSES

  struct sys_info
  {
    sys_seconds begin;
    sys_seconds end;
    seconds offset;
    minutes save;
    string abbrev;
  };

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const sys_info& __si);

  struct local_info
  {
    enum
    {
      unique,
      nonexistent,
      ambiguous
    } result;

    sys_info first;
    sys_info second;
  };

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os, const local_info& __li);

  // EXCEPTION CLASSES

  class nonexistent_local_time
  : public runtime_error
  {
  public:
    template<typename _Duration>
      nonexistent_local_time(const local_time<_Duration>& __tp,
                             const local_info& __i);
  };

  class ambiguous_local_time
  : public runtime_error
  {
  public:
    template<typename Duration>
      ambiguous_local_time(const local_time<Duration>& __tp,
                           const local_info& __i);
  };

  // TIME_ZONE

  enum class choose
  {
    earliest,
    latest
  };

  class time_zone
  {
  public:

    time_zone(time_zone&&) = default;

    time_zone&
    operator=(time_zone&&) = default;

    string_view
    name() const noexcept;

    template<typename _Duration>
      sys_info
      get_info(const sys_time<_Duration>& __st) const;

    template<typename _Duration>
      local_info
      get_info(const local_time<_Duration>& __tp) const;

    template<typename _Duration>
      sys_time<common_type_t<_Duration, seconds>>
      to_sys(const local_time<_Duration>& __tp) const;

    template<typename _Duration>
      sys_time<common_type_t<_Duration, seconds>>
      to_sys(const local_time<_Duration>& __tp, choose __z) const;

    template<typename _Duration>
      local_time<common_type_t<_Duration, seconds>>
      to_local(const sys_time<_Duration>& __tp) const;
  };

  bool
  operator==(const time_zone& __x, const time_zone& __y) noexcept;

  bool
  operator!=(const time_zone& __x, const time_zone& __y) noexcept;

  bool
  operator<(const time_zone& __x, const time_zone& __y) noexcept;

  bool
  operator>(const time_zone& __x, const time_zone& __y) noexcept;

  bool
  operator<=(const time_zone& __x, const time_zone& __y) noexcept;

  bool
  operator>=(const time_zone& __x, const time_zone& __y) noexcept;

  // ZONED_TIME

  const time_zone*
  locate_zone(string_view tz_name);

  const time_zone*
  current_zone();

  template<typename _Tp>
  struct zoned_traits
  { };

  template<>
  struct zoned_traits<const time_zone*>
  {
    static const time_zone*
    default_zone()
    { return chrono::locate_zone("Etc/UTC"); }

    static const time_zone*
    locate_zone(std::string_view name)
    { return chrono::locate_zone(name); }
  };

  template<typename _Duration, typename _TimeZonePtr = const time_zone*>
    class zoned_time
    {
    public:
      using duration = common_type_t<_Duration, seconds>;

    private:

      _TimeZonePtr _M_zone;
      sys_time<duration> _M_tp;

      using traits = zoned_traits<_TimeZonePtr>;

    public:

      zoned_time();

      zoned_time(const zoned_time&) = default;

      zoned_time&
      operator=(const zoned_time&) = default;

      zoned_time(const sys_time<_Duration>& __st);

      explicit zoned_time(_TimeZonePtr __z);

      explicit zoned_time(string_view __name);

      template<typename _Duration2>
        zoned_time(const zoned_time<_Duration2>& __zt) noexcept;

      zoned_time(_TimeZonePtr __z, const sys_time<_Duration>& __st);

      zoned_time(string_view __name, const sys_time<_Duration>& __st);

      zoned_time(_TimeZonePtr __z, const local_time<_Duration>& __tp);

      zoned_time(string_view __name, const local_time<_Duration>& __tp);

      zoned_time(_TimeZonePtr __z, const local_time<_Duration>& __tp,
                 choose __c);

      zoned_time(string_view __name, const local_time<_Duration>& __tp,
                 choose __c);

      template <typename _Duration2, typename _TimeZonePtr2>
        zoned_time(_TimeZonePtr __z,
                   const zoned_time<_Duration2, _TimeZonePtr2>& __zt);

      template <typename _Duration2, typename _TimeZonePtr2>
        zoned_time(_TimeZonePtr __z,
                   const zoned_time<_Duration2, _TimeZonePtr2>& __zt,
                   choose __c);

      zoned_time(string_view name, const zoned_time<_Duration>& __zt);

      zoned_time(string_view name, const zoned_time<_Duration>& __zt,
                 choose __c);

      zoned_time&
      operator=(const sys_time<_Duration>& __st);

      zoned_time&
      operator=(const local_time<_Duration>& __ut);

      operator sys_time<duration>() const;

      explicit
      operator local_time<duration>() const;

      _TimeZonePtr
      get_time_zone() const;

      local_time<duration>
      get_local_time() const;

      sys_time<duration>
      get_sys_time() const;

      sys_info
      get_info() const;
    };

  using zoned_seconds = zoned_time<seconds>;

  template<typename _Duration1, typename _Duration2,
	   typename _TimeZonePtr>
    bool
    operator==(const zoned_time<_Duration1, _TimeZonePtr>& __x,
	       const zoned_time<_Duration2, _TimeZonePtr>& __y);

  template<typename _Duration1, typename _Duration2,
	   typename _TimeZonePtr>
    bool
    operator!=(const zoned_time<_Duration1, _TimeZonePtr>& __x,
	       const zoned_time<_Duration2, _TimeZonePtr>& __y);

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
	       const zoned_time<_Duration, _TimeZonePtr>& __t);

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    basic_ostream<_CharT, _Traits>&
    to_stream(basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const zoned_time<_Duration, _TimeZonePtr>& __tp);

  // TIME ZONE DATABASE

  struct tzdb
  {
    string version;
    vector<time_zone> zones;
    vector<link> links;
    vector<leap> leaps;

    const time_zone*
    locate_zone(string_view tz_name) const;

    const time_zone*
    current_zone() const;

    tzdb* _M_next;
  };

  class tzdb_list
  {
    atomic<tzdb*> _M_head{nullptr};

  public:
    tzdb_list(const tzdb_list&) = delete;
    tzdb_list& operator=(const tzdb_list&) = delete;

    class const_iterator;

    const tzdb& front() const noexcept;

    const_iterator erase_after(const_iterator __p);

    const_iterator begin() const noexcept;
    const_iterator end()   const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend()   const noexcept;
  };

  const tzdb&
  get_tzdb();

  tzdb_list&
  get_tzdb_list();

  // REMOTE TIME ZONE DATABASE

  const tzdb&
  __reload_tzdb();

  string
  remote_version();

  // FORMAT

  template<typename _CharT, typename _Streamable>
    basic_string<_CharT>
    format(const _CharT* __fmt, const _Streamable& __s);

  template<typename _CharT, typename _Streamable>
    basic_string<_CharT>
    format(const locale& __loc, const _CharT* __fmt, const _Streamable& __s);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Streamable>
    basic_string<_CharT, _Traits, _Alloc>
    format(const basic_string<_CharT, _Traits, _Alloc>& __fmt,
	   const _Streamable& __s);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Streamable>
    basic_string<_CharT, _Traits, _Alloc>
    format(const locale& __loc,
	   const basic_string<_CharT, _Traits, _Alloc>& __fmt,
	   const _Streamable& __s);

  // PARSE

  namespace __detail
  {
    struct __parse_result
    {};
  }

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Parsable>
    __detail::__parse_result
    parse(const basic_string<_CharT, _Traits, _Alloc>& __format,
	  _Parsable& __tp);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Parsable>
    __detail::__parse_result
    parse(const basic_string<_CharT, _Traits, _Alloc>& __format,
	  _Parsable& __tp,
	  basic_string<_CharT, _Traits, _Alloc>& __abbrev);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Parsable>
    __detail::__parse_result
    parse(const basic_string<_CharT, _Traits, _Alloc>& __format,
	  _Parsable& __tp,
	  minutes& __offset);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Parsable>
    __detail::__parse_result
    parse(const basic_string<_CharT, _Traits, _Alloc>& __format,
	  _Parsable& __tp,
	  basic_string<_CharT, _Traits, _Alloc>& __abbrev,
	  minutes& __offset);

  // LEAP

  class leap
  {
    sys_seconds _M_date;  // exposition only

  public:

    leap(const leap&) = default;

    leap& operator=(const leap&) = default;

    // Unspecified constructors

    constexpr sys_seconds
    date() const noexcept
    { return this->_M_date; }
  };

  bool
  operator==(const leap& __x, const leap& __y)
  { return __x.date() == __y.date(); }

  bool
  operator!=(const leap& __x, const leap& __y)
  { return !(__x == __y); }

  bool
  operator<(const leap& __x, const leap& __y)
  { return __x < __y; }

  bool
  operator>(const leap& __x, const leap& __y)
  { return __y < __x; }

  bool
  operator<=(const leap& __x, const leap& __y)
  { return !(__y < __x); }

  bool
  operator>=(const leap& __x, const leap& __y)
  { return !(__x < __y); }

  template<typename _Duration>
    bool
    operator==(const leap& __x, const sys_time<_Duration>& __y)
    { return __x.date() == __y; }

  template<typename _Duration>
    bool
    operator==(const sys_time<_Duration>& __x, const leap& __y)
    { return __y == __x; }

  template<typename _Duration>
    bool
    operator!=(const leap& __x, const sys_time<_Duration>& __y)
  { return !(__x == __y); }

  template<typename _Duration>
    bool
    operator!=(const sys_time<_Duration>& __x, const leap& __y)
  { return !(__x == __y); }

  template<typename _Duration>
    bool
    operator<(const leap& __x, const sys_time<_Duration>& __y)
    { return __x.date() < __y; }

  template<typename _Duration>
    bool
    operator<(const sys_time<_Duration>& __x, const leap& __y)
    { return __x < __y.date(); }

  template<typename _Duration>
    bool
    operator>(const leap& __x, const sys_time<_Duration>& __y)
  { return __y < __x; }

  template<typename _Duration>
    bool
    operator>(const sys_time<_Duration>& __x, const leap& __y)
  { return __y < __x; }

  template<typename _Duration>
    bool
    operator<=(const leap& __x, const sys_time<_Duration>& __y)
  { return !(__y < __x); }

  template<typename _Duration>
    bool
    operator<=(const sys_time<_Duration>& __x, const leap& __y)
  { return !(__y < __x); }

  template<typename _Duration>
    bool
    operator>=(const leap& __x, const sys_time<_Duration>& __y)
  { return !(__x < __y); }

  template<typename _Duration>
    bool
    operator>=(const sys_time<_Duration>& __x, const leap& __y)
  { return !(__x < __y); }

  // LINK

  class link
  {
  private:

    string_view _M_name;    // exposition only
    string_view _M_target;  // exposition only

  public:

    link(link&&) = default;

    link& operator=(link&&) = default;

    // Unspecified constructors

    string_view
    name() const noexcept
    { return this->_M_name; }

    string_view
    target() const noexcept
    { return this->_M_target; }
  };

  bool
  operator==(const link& __x, const link& __y)
  { return __x.name() == __y.name(); }

  bool
  operator!=(const link& __x, const link& __y)
  { return !(__x == __y); }

  bool
  operator<(const link& __x, const link& __y)
  { __x.name() < __y.name(); }

  bool
  operator>(const link& __x, const link& __y)
  { return __y < __x; }

  bool
  operator<=(const link& __x, const link& __y)
  { return !(__y < __x); }

  bool
  operator>=(const link& __x, const link& __y)
  { return !(__x < __y); }

  constexpr chrono::weekday Sunday{0};
  constexpr chrono::weekday Monday{1};
  constexpr chrono::weekday Tuesday{2};
  constexpr chrono::weekday Wednesday{3};
  constexpr chrono::weekday Thursday{4};
  constexpr chrono::weekday Friday{5};
  constexpr chrono::weekday Saturday{6};

  constexpr chrono::month January{1};
  constexpr chrono::month February{2};
  constexpr chrono::month March{3};
  constexpr chrono::month April{4};
  constexpr chrono::month May{5};
  constexpr chrono::month June{6};
  constexpr chrono::month July{7};
  constexpr chrono::month August{8};
  constexpr chrono::month September{9};
  constexpr chrono::month October{10};
  constexpr chrono::month November{11};
  constexpr chrono::month December{12};

} // namespace chrono

inline namespace literals
{
namespace chrono_literals
{

  constexpr chrono::day
  operator""d(unsigned long long __d) noexcept
  { return chrono::day{static_cast<unsigned>(__d)}; }

  constexpr chrono::year
  operator""y(unsigned long long __y) noexcept
  { return chrono::year{static_cast<int>(__y)}; }

} // chrono_literals
} // namespace literals

} // namespace std

