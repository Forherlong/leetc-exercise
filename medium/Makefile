CXX = gcc
CFLAGS = -g

Obj = addtwonumber
Src = add_two_numbers.c

$(Obj):$(Src)
	$(CXX) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	-rm $(Obj)