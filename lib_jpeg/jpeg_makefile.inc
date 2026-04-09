FINAL_CFLAGS += -I$(JPEG)

JPEG_SRC = \
    jpgd.cpp \
    jpge.cpp

JPEG_OBJS = $(JPEG_SRC:.cpp=.o)
OBJS += $(JPEG_OBJS)

JPEG_DEPS = $(JPEG)*.h

$(JPEG_OBJS): %.o: $(JPEG)%.cpp $(JPEG_DEPS) $(SD_DEPS)
	$(CXX) $(FINAL_CFLAGS) -c $<
