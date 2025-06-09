#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <stdint.h>

/**
 * @brief Critical assert macro
 * @param FILE_HASH CRC32 hash of the filename
 * @param COND The condition to check
 * @param RETVAL The return value which gets returned when check fails
 * @return The retval which was specified as parameter
 */
#define ATS_CRIT_ASSERT(HASH, COND, RETVAL)      \
do                                                        \
{                                                         \
    if (!(cond))                                          \
    {                                                     \
        ats_critical_assert((FILE_HASH), (__LINE__)); \
        return (retval);                                  \
    }                                                     \
} while (0)


/**
 * @brief Critical assert macro with return
 * @param FILE_HASH CRC32 hash of the filename
 * @param COND The condition to check
 * @param RETVAL The return value which gets returned when check fails
 * @return The retval which was specified as parameter
 */
#define ATS_CRIT_ASSERT_RET(HASH, COND, RETVAL) \
do                                                        \
{                                                         \
    if (!(cond))                                          \
    {                                                     \
        ats_critical_assert((FILE_HASH), (__LINE__)); \
        return (retval);                                  \
    }                                                     \
} while (0)

/**
 * @brief Non-critical assert macro
 * @param FILE_HASH CRC32 hash of the filename
 * @param COND The condition to check
 * @param RETVAL The return value which gets returned when check fails
 * @return The retval which was specified as parameter
 */
#define ATS_NON_CRIT_ASSERT(HASH, COND, RETVAL) \
do                                                        \
{                                                         \
    if (!(cond))                                          \
    {                                                     \
        ats_non_critical_assert((FILE_HASH), (__LINE__)); \
        return (retval);                                  \
    }                                                     \
} while (0)

/**
 * @brief Non-critical assert macro with return
 * @param FILE_HASH CRC32 hash of the filename
 * @param COND The condition to check
 * @param RETVAL The return value which gets returned when check fails
 * @return The retval which was specified as parameter
 */
#define ATS_NON_CRIT_ASSERT_RET(HASH, COND, RETVAL) \
do                                                        \
{                                                         \
    if (!(cond))                                          \
    {                                                     \
        ats_non_critical_assert((FILE_HASH), (__LINE__)); \
        return (retval);                                  \
    }                                                     \
} while (0)


void ats_critical_assert(const uint32_t file_hash, const uint32_t line);
void ats_non_critical_assert(const uint32_t file_hash, const uint32_t line);

#endif /* ERROR_HANDLING_H */