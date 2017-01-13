.PHONY: clean All

All:
	@echo "----------Building project:[ DataServer - Debug ]----------"
	@cd "DataServer" && "$(MAKE)" -f  "DataServer.mk"
clean:
	@echo "----------Cleaning project:[ DataServer - Debug ]----------"
	@cd "DataServer" && "$(MAKE)" -f  "DataServer.mk" clean
