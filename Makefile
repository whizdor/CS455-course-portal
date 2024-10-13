TARGET = course_portal
SRCS = main.cpp course.cpp admin.cpp student.cpp interface.cpp admin_interface.cpp student_interface.cpp utils.cpp
HEADERS = course.h admin.h student.h interface.h admin_interface.h student_interface.h utils.h
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)
	rm -f $(OBJS)
	./course_portal

$(TARGET): $(OBJS)
	g++ -w -o $(TARGET) $(OBJS)

%.o: sources/%.cpp $(HEADERS)
	g++ -w -c $<

run: $(TARGET)
	rm -f $(OBJS)
	./$(TARGET)
