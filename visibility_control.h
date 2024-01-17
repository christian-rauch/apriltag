#ifndef APRILTAG__VISIBILITY_CONTROL_H_
#define APRILTAG__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define APRILTAG_EXPORT __attribute__ ((dllexport))
    #define APRILTAG_IMPORT __attribute__ ((dllimport))
  #else
    #define APRILTAG_EXPORT __declspec(dllexport)
    #define APRILTAG_IMPORT __declspec(dllimport)
  #endif
  #ifdef APRILTAG_BUILDING_LIBRARY
    #define APRILTAG_PUBLIC APRILTAG_EXPORT
  #else
    #define APRILTAG_PUBLIC APRILTAG_IMPORT
  #endif
  #define APRILTAG_PUBLIC_TYPE APRILTAG_PUBLIC
  #define APRILTAG_LOCAL
#else
  #define APRILTAG_EXPORT __attribute__ ((visibility("default")))
  #define APRILTAG_IMPORT
  #if __GNUC__ >= 4
    #define APRILTAG_PUBLIC __attribute__ ((visibility("default")))
    #define APRILTAG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define APRILTAG_PUBLIC
    #define APRILTAG_LOCAL
  #endif
  #define APRILTAG_PUBLIC_TYPE
#endif

#endif  // APRILTAG__VISIBILITY_CONTROL_H_
