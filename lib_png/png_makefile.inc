PNG_ORIG = $(PNG)png/

FINAL_CFLAGS += -I$(PNG_ORIG)

PNG_SRC += \
    png.c \
    pngerror.c \
    pngget.c \
    pngmem.c \
    pngpread.c \
    pngread.c \
    pngrio.c \
    pngrtran.c \
    pngrutil.c \
    pngset.c \
    pngtrans.c \
    pngwio.c \
    pngwrite.c \
    pngwtran.c \
    pngwutil.c

ifneq (,$(findstring arm,$(TARGET_ARCH)))
PNG_SRC2 += \
    arm_init.c \
    filter_neon_intrinsics.c \
    palette_neon_intrinsics.c
PNG_SRC3 += \
    filter_neon.S
endif

ifneq (,$(findstring x86,$(TARGET_ARCH)))
PNG_SRC4 += \
    filter_sse2_intrinsics.c \
    intel_init.c
endif

PNG_OBJS = $(PNG_SRC:.c=.o)
PNG_OBJS2 = $(PNG_SRC2:.c=.o)
PNG_OBJS3 = $(PNG_SRC3:.S=.o)
PNG_OBJS4 = $(PNG_SRC4:.c=.o)
OBJS += $(PNG_OBJS) $(PNG_OBJS2) $(PNG_OBJS3) $(PNG_OBJS4)

PNG_DEPS = $(PNG_ORIG)*.h

$(PNG_OBJS): %.o: $(PNG_ORIG)%.c $(PNG_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $<

$(PNG_OBJS2): %.o: $(PNG_ORIG)arm/%.c $(PNG_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $<

$(PNG_OBJS3): %.o: $(PNG_ORIG)arm/%.S $(PNG_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $<

$(PNG_OBJS4): %.o: $(PNG_ORIG)intel/%.c $(PNG_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $<
