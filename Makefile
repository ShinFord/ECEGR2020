.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_6 - Release ]----------"
	@cd "Lab_6" && "$(MAKE)" -f  "Lab_6.mk"
clean:
	@echo "----------Cleaning project:[ Lab_6 - Release ]----------"
	@cd "Lab_6" && "$(MAKE)" -f  "Lab_6.mk" clean
