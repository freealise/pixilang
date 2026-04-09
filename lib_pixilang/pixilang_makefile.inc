FINAL_CFLAGS += -I$(PIXILANG)

PIXILANG_SRC += \
    pixilang.cpp \
    pixilang_compiler.cpp \
    pixilang_symtab.cpp \
    pixilang_utils.cpp \
    pixilang_vm_audio.cpp \
    pixilang_vm_container.cpp \
    pixilang_vm_font.cpp \
    pixilang_vm_gfx.cpp \
    pixilang_vm_gfx_triangle.cpp \
    pixilang_vm_load_save.cpp \
    pixilang_vm_builtin_fns.cpp \
    pixilang_vm_builtin_fns_native.cpp \
    pixilang_vm_data_processing.cpp \
    pixilang_vm_opengl.cpp
PIXILANG_SRC2 += \
    pixilang_vm.cpp

PIXILANG_OBJS = $(PIXILANG_SRC:.cpp=.o)
PIXILANG_OBJS2 = $(PIXILANG_SRC2:.cpp=.o)
OBJS += $(PIXILANG_OBJS) $(PIXILANG_OBJS2)

PIXILANG_DEPS = $(PIXILANG)*.h

$(PIXILANG_OBJS): %.o: $(PIXILANG)%.cpp $(PIXILANG_DEPS) $(SD_DEPS)
	$(CXX) $(FINAL_CFLAGS) -c $<

$(PIXILANG_OBJS2): %.o: $(PIXILANG)%.cpp $(PIXILANG_DEPS) $(SD_DEPS)
	$(CXX) $(FINAL_CFLAGS) -c $<
