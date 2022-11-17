# Use "make TARGET=Linux all" to build for Linux

export

STEPS := all tests apps clean check info tools docs %.debug
.PHONY: $(STEPS) %.debug shell docker lint lint-changed

CWD := $(shell pwd)
HOST := $(shell uname)

# NPROC :=
# ifeq ($(HOST),Darwin)
#   NPROC = sysctl -n hw.physicalcpu
# else
#   NPROC = nproc
# endif

# TARGET ?= $(HOST)
# BUILD_TYPE ?= Debug
MAKE := make -f Build/Makefile
DOCKER_EXE := DOCKER_BUILDKIT=0 docker
DOCKER ?= 1

# DOCKERFILE := Build/Docker/Dockerfile

ENABLE_TTY =
# MAKE_DOCKER = $(DOCKER_EXE) build - < $(DOCKERFILE) | tee /dev/stderr | grep "Successfully built" | cut -d ' ' -f 3
MAKE_DOCKER := gsoap
RUN = $(DOCKER_EXE) run \
  --cap-add=SYS_PTRACE \
  --security-opt seccomp=unconfined \
  --mount type=bind,source="$(CWD)",target=/build \
  --rm \
  -i $(ENABLE_TTY) $(MAKE_DOCKER)

# Else run make inside docker
MAKE := $(RUN) $(MAKE)

# define make_target
#   $(1):
# 	@$(2) $$@

# endef

# $(eval $(foreach step,$(STEPS),$(call make_target,$(step),$(MAKE) PAL=$(TARGET))))

shell: ENABLE_TTY=-t
shell:
	@$(RUN) bash

docker:
	@$(MAKE_DOCKER)
