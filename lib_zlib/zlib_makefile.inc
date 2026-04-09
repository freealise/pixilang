ZLIB_ORIG = $(ZLIB)zlib/

FINAL_CFLAGS += -I$(ZLIB_ORIG)

ZLIB_SRC += \
    adler32.c \
    compress.c \
    crc32.c \
    deflate.c \
    infback.c \
    inffast.c \
    inflate.c \
    inftrees.c \
    trees.c \
    uncompr.c \
    zutil.c

ZLIB_OBJS = $(ZLIB_SRC:%.c=zlib_%.o)
OBJS += $(ZLIB_OBJS)

ZLIB_DEPS = $(ZLIB_ORIG)*.h

$(ZLIB_OBJS): zlib_%.o: $(ZLIB_ORIG)%.c $(ZLIB_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $< -o $@
