FINAL_CFLAGS += -I$(GIF)

GIF_SRC += \
    dgif_lib.c \
    egif_lib.c \
    gif_err.c \
    gif_hash.c \
    gifalloc.c

GIF_OBJS = $(GIF_SRC:.c=.o)
OBJS += $(GIF_OBJS)

GIF_DEPS = $(GIF)*.h

$(GIF_OBJS): %.o: $(GIF)%.c $(GIF_DEPS)
	$(CC) $(FINAL_CFLAGS) -c $<
