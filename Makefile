EXECUTABLE = MemoryGame
DIRS = src objs

subdir:
	for dir in $(DIRS); do \
	$(MAKE) -C $$dir; \
	done

exec:
	./$(EXECUTABLE)

clean:
	rm $(EXCUTABLE)
	rm ./objs/*.o

.PHONY:	subdir
