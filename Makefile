.PHONY: build-and-run restart clean attach format

execute exec exe e:
	# docker exec -it execute bash -c "mkdir -p build && cd build && cmake .. && cmake --build . --target ${ARGS} && ./${ARGS}"
	@if [ -z "$(ARGS)" ]; then \
		echo "No target specified, building all targets..."; \
		docker exec -it execute bash -c "mkdir -p build && cd build && cmake .. && cmake --build . && ./prelog"; \
	else \
		echo "Building target $(ARGS)..."; \
		docker exec -it execute bash -c "mkdir -p build && cd build && cmake .. && cmake --build . --target $(ARGS) && ./prelog &&./$(ARGS)"; \
	fi

# rebuild all containers and format code
restart res r: format
	docker compose down && docker compose up --build -d

# clean all executables
clean c:
	docker exec -it execute bash -c "rm -rf build"

attach a:
	docker exec -it frontend bash

format:
	(echo "=== Formatting JavaScript with Prettier... ===" && prettier services/frontend --write) && echo && (echo "=== Formatting Python with Black ===" && black services/backend && echo)

