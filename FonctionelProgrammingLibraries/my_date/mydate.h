#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include "mylibrary.h"
using namespace std;
namespace mydate
{
struct stdate
{
    short year;
    short month;
    short day;
};
string num_to_text(long long int num)
{
    if (num == 0)
    {
        return "";
    }
    if (num > 0&& num < 20)
    {
        string arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        return (arr[num]);
    }
    if (num > 19 && num < 100)
    {
        string arr[] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};
        return (arr[num / 10] + " " + num_to_text(num % 10));
    }
    if (num > 99 && num < 1000)
    {
        string arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        return (arr[num / 100] + " hundred " + num_to_text(num % 100) + " ");
    }
    if (num > 999 && num < 1000000)
    {
         return (num_to_text(num / 1000) + " thousand " + num_to_text(num % 1000));
    }
    if (num > 999999 && num < 1000000000)
    {
        return (num_to_text(num / 1000000) + " million " + num_to_text(num % 1000000));
    }
    if (num > 999999999 && num < 1000000000000)
    {
        return (num_to_text(num / 1000000000) + " billion " + num_to_text(num % 1000000000));
    }
}
bool is_leap_year(short year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}
bool is_leap_year_one_line(short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

short number_of_days_in_year(short year)
{
    return (is_leap_year_one_line(year) ? 366 : 365);
}
short number_of_hours_in_year(short year)
{
    return (number_of_days_in_year(year) * 24);
}
int number_of_minutes_in_year(short year)
{
    return (number_of_hours_in_year(year) * 60);
}
int number_of_seconds_in_year(short year)
{
    return (number_of_minutes_in_year(year) * 60);
}
void print_year_info(short year)
{
    cout << "\nNumber of days in Year    [" << year << "] is " << number_of_days_in_year(year);
    cout << "\nNumber of hours in Year   [" << year << "] is " << number_of_hours_in_year(year);
    cout << "\nNumber of minutes in Year [" << year << "] is " << number_of_minutes_in_year(year);
    cout << "\nNumber of seconds in Year [" << year << "] is " << number_of_seconds_in_year(year);
}
short month_days(short month)
{
    if (month == 2)
        return 28;
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else
        return 30;
}
short month_days_two_lines_of_code(short month, short year)
{
    if (month < 1 || month > 12)
        return 0;
    short arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (is_leap_year(year) && month == 2? 29 :arr[month]);
}
short number_of_days_in_month(short year, short month)
{
    return ((is_leap_year_one_line(year) && month == 2) ? 29 : month_days(month));
}
short number_of_hours_in_month(short year, short month)
{
    return (number_of_days_in_month(year, month) * 24);
}
int number_of_minutes_in_month(short year, short month)
{
    return (number_of_hours_in_month(year, month) * 60);
}
int number_of_seconds_in_month(short year, short month)
{
    return (number_of_minutes_in_month(year, month) * 60);
}
void print_month_info(short year, short month)
{
    cout << "\nNumber of days in Year    [" << year << "] is " << number_of_days_in_month(year, month);
    cout << "\nNumber of hours in Year   [" << year << "] is " << number_of_hours_in_month(year, month);
    cout << "\nNumber of minutes in Year [" << year << "] is " << number_of_minutes_in_month(year, month);
    cout << "\nNumber of seconds in Year [" << year << "] is " << number_of_seconds_in_month(year, month);
}
string day_name(short d)
{
    switch (d)
    {
    case 0:
        return "sunday";
    case 1:
        return "monday";
    case 2:
        return "tuesday";
    case 3:
        return "wednesday";
    case 4:
        return "thursday";
    case 5:
        return "friday";
    case 6:
        return "saturday";
    }
}
string month_name(short m)
{
    switch (m)
    {
    case 1:
        return "Jan";
    case 2:
        return "Feb";
    case 3:
        return "Mar";
    case 4:
        return "Apr";
    case 5:
        return "May";
    case 6:
        return "Jun";
    case 7:
        return "Jul";
    case 8:
        return "Aug";
    case 9:
        return "Sep";
    case 10:
        return "Oct";
    case 11:
        return "Nov";
    case 12:
        return "Dec";
    }
}
short day_order(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    short d = (day + y + (y / 4) - (y / 100) + y / 400 + ((31 * m) / 12)) % 7;
    return d;
}
short day_order(stdate date)
{
    return (day_order(date.year, date.month, date.day));
}
void print_date(short year, short month, short day)
{
    short d_order = day_order(year, month, day);
    cout << "\nDate     :" << day << "/" << month << "/" << year;
    cout << "\nDay order:" << d_order;
    cout << "\nDay name :" << day_name(d_order);
}
void print_month_calendar(short year, short month)
{
    cout << "\n________________" << month_name(month) << "________________\n\n";
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    short d_order = day_order(year, month, 1);
    short h = 0, k = 1;
    string arr[36];
    for (short j = 0; j < d_order; j++)
    {
        arr[h] = ' ';
        h++;
    }
    for (short i = h; i < (d_order + month_days(month)); i++)
    {
        arr[h] = to_string(k);
        k++;
        h++;
    }
    for (short i = 0; i < 36 ; i++)
    {
        cout << setw(2) << arr[i] << "   ";
        if ((i + 1) % 7 == 0)
            cout << endl;
    }
    cout << "________________________________\n";
}
void print_month_calendar_2(short year, short month)
{
    cout << "\n________________" << month_name(month) << "________________\n\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    short current = day_order(year, month, 1);
    short numberofdays = number_of_days_in_month(year, month);
    short i;
    for (i = 0; i < current; i++)
    {
        cout <<"     ";
    }
    for (short j = 1; j <= numberofdays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }
    cout << "\n__________________________________\n";
}
void print_yearly_calendar(short year)
{
    cout << "\n__________________________________\n";
    cout << "\n__________" << "Calendar - " << year << "_________\n\n";
    cout << "\n__________________________________\n";
    for (short j = 1; j <= 12; j++)
    {
        print_month_calendar_2(year, j);
    }
}
short number_of_days_from_the_begenning_of_the_year(short year, short month, short day)
{
    short n_days = 0;
    for (short j = 1; j < month; j++)
    {
        n_days += number_of_days_in_month(year, j);
    }
    n_days += day;
    return (n_days);
}

stdate date_from_day_order_in_year(short year, short day_order)
{
    stdate date;
    date.year = year;
    short current_month;
    for (current_month = 1; current_month <= 12; current_month++)
    {
        if (day_order <= number_of_days_in_month(year, current_month))
            break;
        day_order -= number_of_days_in_month(year, current_month);
    }
    date.month = current_month;
    date.day = day_order;
    return date;
 }
stdate future_date_after_adding_days(short year, short month, short day, short added)
{
    short still_days_in_year = 0;
    if (added > (still_days_in_year = number_of_days_in_year(year) - number_of_days_from_the_begenning_of_the_year(year, month, day)))
    {
        added -= still_days_in_year;
        year++;
    }
    else
    {
        return(date_from_day_order_in_year(year, number_of_days_from_the_begenning_of_the_year(year, month, day) + added));
    }
    while (added > (still_days_in_year = number_of_days_in_year(year)))
    {
        added -= still_days_in_year;
        year++;
    }
    return (date_from_day_order_in_year(year, added));
}
enum endate_compare{date1, date2, eq};
stdate read_date(string msg)
{
    stdate date;
    cout << endl << msg;
    cout << "\nenter a day:";
    cin >> date.day;
    cout << "\nenter a month:";
    cin >> date.month;
    cout << "\nenter a year:";
    cin >> date.year;
    return date;
}
void print_date(stdate date)
{
    cout << endl << day_name(day_order(date)) << " , ";
    printf("%d/%d/%d", date.year, date.month, date.day);
}
endate_compare dates_compare(stdate date_1, stdate date_2)
{
    if (date_1.year > date_2.year)
        return date1;
    else if (date_1.year < date_2.year)
        return date2;
    else
    {
        if (date_1.month > date_2.month)
            return date1;
        else if (date_1.month < date_2.month)
            return date2;
        else
        {
            if (date_1.day > date_2.day)
                return date1;
            else if (date_1.day < date_2.day)
                return date2;
            else
                return eq;
        }
    }
}
bool is_last_day_in_month(stdate date)
{
    return (date.day == number_of_days_in_month(date.year, date.month));
}
bool is_last_month_in_year(short month)
{
    return (month == 12);
}
void increase_date_by_one_day(stdate& date)
{
    date.day++;
    if (date.day > number_of_days_in_month(date.year, date.month))
    {
        date.day = 1;
        date.month++;
        if (date.month > 12)
        {
            date.month = 1;
            date.year++;
        }
    }
}
stdate increase_date_by_one_day2(stdate date)
{
    if (is_last_day_in_month(date))
    {
        date.day = 1;
        if (is_last_month_in_year(date.month))
        {
            date.month = 1;
            date.year++;
        }
        else
            date.month++;
    }
    else
        date.day++;
    return date;
}
short difference_between_two_dates(stdate date_1, stdate date_2, bool end_day_encluded = false)
{
    short diff = 0;
    if (dates_compare(date_1, date_2) == date2)
    {
        while (dates_compare(date_1, date_2)!= eq)
        {
            diff++;
            increase_date_by_one_day(date_1);
        }
        return (end_day_encluded? ++diff:diff);
    }
    else if (dates_compare(date_1, date_2) == date1)
    {
        while (dates_compare(date_1, date_2) != eq)
        {
            diff++;
            increase_date_by_one_day(date_2);
        }
        return (end_day_encluded? -(++diff) : -diff);
    }
    else
        return 0;
}
/**short age_in_days(stdate birth_date)
{
    stdate current_date;
    time_t t = time(0);
    tm* ltm = localtime(&t);
    
    current_date.year = ltm->tm_year + 1900;
    current_date.month = ltm->tm_mon + 1;
    current_date.day = ltm->tm_mday;
    return (difference_between_two_dates(birth_date, current_date));
}*/
/*stdate get_current_date(void)
{
    stdate current_date;
    time_t t = time(0);
    tm* ltm = localtime(&t);

    current_date.year = ltm->tm_year + 1900;
    current_date.month = ltm->tm_mon + 1;
    current_date.day = ltm->tm_mday;
    return current_date;
}*/
stdate increase_date_by_X_days(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        increase_date_by_one_day(date);

    return date;
}
stdate increase_date_by_one_week(stdate date)
{
    for (short i = 0; i < 7; i++)
        increase_date_by_one_day(date);

    return date;
}
stdate increase_date_by_X_week(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = increase_date_by_one_week(date);
 
    return date;
}
stdate increase_date_by_one_month(stdate date)
{
    if (is_last_month_in_year(date.month))
    {
        date.month = 1;
        date.year++;
    }
    else
        date.month++;
    short number_of_days = number_of_days_in_month(date.year, date.month);
    if (date.day > number_of_days)
        date.day = number_of_days;

    return date;
}
stdate increase_date_by_X_months(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = increase_date_by_one_month(date);

    return date;
}
stdate increase_date_by_one_year(stdate date)
{
    date.year++;
    return date;
}
stdate increase_date_by_X_years(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = increase_date_by_one_year(date);
    return date;
}
stdate increase_date_by_X_years_faster(stdate date, short X)
{
    date.year += X;
    return date;
}
stdate increase_date_by_one_decade(stdate date)
{
    for (short i = 0; i < 10; i++)
        date = increase_date_by_one_year(date);
    return date;
}
stdate increase_date_by_one_decade_faster(stdate date)
{
    date.year+=10;
    return date;
}
stdate increase_date_by_X_decade(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = increase_date_by_one_decade(date);
    
    return date;
}
stdate increase_date_by_X_decade_faster(stdate date, short X)
{
    date.year += (X * 10);

    return date;
}
stdate increase_date_by_one_century(stdate date)
{
    date.year += 100;
    return date;
}
stdate increase_date_by_one_millennium(stdate date)
{
    date.year += 1000;
    return date;
}
bool is_first_day_on_month(short day)
{
    return (day == 1);
}
stdate decrease_date_by_one_day(stdate date)
{
    if (is_first_day_on_month(date.day))
    {
        if (date.month == 1)
        {
            date.day = 31;
            date.month = 12;
            date.year--;
            return date;
        }
        date.month--;
        date.day = number_of_days_in_month(date.year, date.month);
        return date;
    }
    date.day--;
    return date;
}
stdate decrease_date_by_X_days(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = decrease_date_by_one_day(date);
                
    return date;
}
stdate decrease_date_by_one_week(stdate date)
{
    for (short i = 0; i < 7; i++)
        date = decrease_date_by_one_day(date);

    // or we can do this:
    // date = decrease_date_by_X_days(date, 7);

    return date;
}
stdate decrease_date_by_one_month(stdate date)
{
     if (date.month == 1)
     {
         date.month = 12;
         date.year--;
         return date;
     }
     if (is_last_day_in_month(date))
     {
         date.month--;
         date.day = number_of_days_in_month(date.year, date.month);
         return date;
     }
     date.month--;
     return date;
}
stdate decrease_date_by_X_months(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = decrease_date_by_one_month(date);

    return date;
}
stdate decrease_date_by_one_year(stdate date)
{
    for (short i = 0; i < 12; i++)
        date = decrease_date_by_one_month(date);

    // date = decrease_date_by_X_months(date);
    return date;
}
stdate decrease_date_by_X_years(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = decrease_date_by_one_year(date);

    return date;
}
stdate decrease_date_by_X_years_faster(stdate date, short X)
{
    date.year -= X;
    return date;
}
stdate decrease_date_by_one_decade(stdate date)
{
    for (short i = 0; i < 10; i++)
        date = decrease_date_by_one_year(date);

    return date;
}
stdate decrease_date_by_X_decades(stdate date, short X)
{
    for (short i = 0; i < X; i++)
        date = decrease_date_by_one_decade(date);

    return date;
}
stdate decrease_date_by_X_decades_faster(stdate date, short X)
{
    date.year -= 10 * X;
    return date;
}
stdate decrease_date_by_one_century(stdate date)
{
    date.year -= 100;
    return date;
}
stdate decrease_date_by_one_millennium(stdate date)
{
    date.year -= 1000;
    return date;
}

bool is_end_of_week(stdate date)
{
    return (day_order(date) == 6);
}
bool is_week_end(stdate date)
{
    short d_order = day_order(date);
    return (d_order == 5 || d_order == 6);
}
bool is_business_day(stdate date)
{
    return (!is_week_end(date));
}
short days_until_end_of_week(stdate date)
{
    return (6 - day_order(date));
}
short days_until_end_of_month(stdate date)
{
    return (number_of_days_in_month(date.year, date.month) - date.day + 1);
}
short days_until_end_of_year(stdate date)
{
    short year_days = (is_leap_year_one_line(date.year) ? 366 : 365);
    return (year_days - number_of_days_from_the_begenning_of_the_year(date.year, date.month, date.day) + 1);
}
short actual_vacation_days(stdate date_1, stdate date_2)
{
    short vacation_ds = 0;
    if (dates_compare(date_1, date_2) == date2)
    {
        while (dates_compare(date_1, date_2) != eq)
        {
            if (is_business_day(date_1))
                vacation_ds++;
            increase_date_by_one_day(date_1);
        }
    }
    else
        cout << "Please enter a valid date! (date2 should be bigger than date1!)\n";
    return (vacation_ds);
}
stdate vacation_return_date(stdate dateFrom, short vacation_days)
{
    while (vacation_days != 0)
    {
        if (is_business_day(dateFrom))
            vacation_days--;

        increase_date_by_one_day(dateFrom);
    }
    return (dateFrom);
}
bool is_date1_after_date2(stdate date_1, stdate date_2)
{
    return (dates_compare(date_1, date_2) == date1);
}
struct stperiod
{
    stdate start_date;
    stdate end_date;
};
void swap_periods(stperiod& period1, stperiod& period2)
{
    stperiod temp;
    temp.start_date = period1.start_date;
    temp.end_date = period1.end_date;

    period1.start_date = period2.start_date;
    period1.end_date = period2.end_date;

    period2.start_date = temp.start_date;
    period2.end_date = temp.end_date;
}
bool is_periods_overlap(stperiod period1, stperiod period2)
{
    if (!dates_compare(period2.end_date, period1.end_date) == date1)
        swap_periods(period1, period2);
    return (dates_compare(period1.end_date, period2.start_date) != date2);
}
stperiod read_period(string msg)
{
    stperiod period;
    cout << msg;
    do
    {
        period.start_date = read_date("Enter start date:");
        period.end_date = read_date("Enter end date:");
    } while (dates_compare(period.start_date, period.end_date) == date1);
    return period;
}
short period_length_in_days(stperiod period, bool end_day_encluded = false)
{
    short length = 0;
    while (dates_compare(period.start_date, period.end_date) != eq)
    {
        increase_date_by_one_day(period.start_date);
        length++;
    }
    return (end_day_encluded ? ++length : length);
    //or we can do
    // return(get_difference_between_two_dates(period.start_date, period.end_date, end_day_encluded);
}
bool is_date_within_period(stdate date, stperiod period)
{
    return (dates_compare(date, period.start_date) == date1 && dates_compare(date, period.end_date) == date2);
}
short count_overlap_days_between_periords(stperiod period1, stperiod period2)
{
    if (is_periods_overlap(period1, period2))
    {
        short days = difference_between_two_dates(period1.end_date, period2.start_date);
        return (dates_compare(period1.end_date, period2.start_date) == date2 ? days : -days);
    }
    else
        return 0;
}
bool is_valid_date(stdate date)
{
    if (date.day <= 0 || date.month <= 0 || date.year <= 0)
        return 0;
    return (date.month <= 12 && date.day <= number_of_days_in_month(date.year, date.month));
}
vector<string> split_string(string date, string delim)
{
    short pos = 0;
    string word = "";
    vector <string> vstring;
    while ((pos = date.find(delim)) != std::string::npos)
    {
        word = date.substr(0, pos);
        if (word != "")
            vstring.push_back(word);
        date.erase(0, pos + delim.length());
    }
    if (date != "")
        vstring.push_back(date);
    return vstring;
}
void trim_left(string &str)
{
    while (str[0] != ' ')
        str.erase(0, 1);
}
void trim_right(string &str)
{
    short length = str.length();
    while (str[length] != ' ')
    {
        str.erase(length - 1, length);
        length--;
    }
}
stdate string_to_stdate(string date)
{
    stdate dat;

    vector<string>vstring = split_string(date, "/");
    dat.day = stoi(vstring[0]);
    dat.month = stoi(vstring[1]);
    dat.year = stoi(vstring[2]);
    return dat;
}
string stdate_to_string(stdate date)
{
    string strdate = "";
    strdate += to_string(date.day);
    strdate += "/";
    strdate += to_string(date.month);
    strdate += "/";
    strdate += to_string(date.year);
    return (strdate);
}
string replace_word_in_string(string& str, string wordtoreplace, string replacewith)
{
    short pos = str.find(wordtoreplace);
    while (pos != std::string::npos)
    {
        str.replace(pos, wordtoreplace.length(),  replacewith);
        pos = str.find(wordtoreplace);
    }
    return str;
}
string date_format(string strdate, string format)
{
    stdate date = string_to_stdate(strdate);
    string formatted_string = "";
    formatted_string = replace_word_in_string(format, "dd", to_string(date.day));
    formatted_string = replace_word_in_string(format, "mm", to_string(date.month));
    formatted_string = replace_word_in_string(format, "yyyy", to_string(date.year));

    return formatted_string;
}
}
