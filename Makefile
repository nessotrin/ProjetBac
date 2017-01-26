.PHONY: clean All

All:
	@echo "----------Building project:[ UserInterface - Debug ]----------"
	@cd "UserInterface" && "$(MAKE)" -f  "UserInterface.mk"
clean:
	@echo "----------Cleaning project:[ UserInterface - Debug ]----------"
	@cd "UserInterface" && "$(MAKE)" -f  "UserInterface.mk" clean
