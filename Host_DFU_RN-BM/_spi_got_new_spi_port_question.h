#if (\
        defined(__32MX120F064H__)    || \
        defined(__32MX130F128H__)    || \
        defined(__32MX130F128L__)    || \
        defined(__32MX150F256H__)    || \
        defined(__32MX150F256L__)    || \
        defined(__32MX170F512H__)    || \
        defined(__32MX170F512L__)    || \
        defined(__32MX230F128H__)    || \
        defined(__32MX230F128L__)    || \
        defined(__32MX250F256H__)    || \
        defined(__32MX250F256L__)    || \
        defined(__32MX270F512H__)    || \
        defined(__32MX270F512L__)    || \
        defined(__32MX530F128H__)    || \
        defined(__32MX530F128L__)    || \
        defined(__32MX550F256H__)    || \
        defined(__32MX550F256L__)    || \
        defined(__32MX570F512H__)    || \
        defined(__32MX570F512L__)    || \
      (__PIC32_FEATURE_SET__ == 330) || \
      (__PIC32_FEATURE_SET__ == 350) || \
      (__PIC32_FEATURE_SET__ == 370) || \
      (__PIC32_FEATURE_SET__ == 430) || \
      (__PIC32_FEATURE_SET__ == 450) || \
      (__PIC32_FEATURE_SET__ == 470) || \
        defined(__32MXGENERIC__)     || \
     ((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299))\
    )
  #define _GOT_NEW_SPI_PORT
#else
  #undef  _GOT_NEW_SPI_PORT
#endif
