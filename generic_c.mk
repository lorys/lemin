# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generic_c.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 17:30:55 by pcarles           #+#    #+#              #
#    Updated: 2019/02/25 23:44:47 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Default value for target's name (name of the current working directory)
CURRENT_DIR		:= $(shell pwd)
TARGETS			?= $(shell basename $(CURRENT_DIR))

# Default values for compilation flags
CC				?= gcc
C_FLAGS			?= -Wall -Wextra -Werror
LD_FLAGS		?=
DEP_FLAGS		?= -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

# Default values for debug flags
DEBUG			?= 0
C_FLAGS_DEBUG	?= -g3 -fsanitize=address
LD_FLAGS_DEBUG	?= -fsanitize=address

# Default values for directories
SRCDIR			?= src
HDRDIR			?= includes
LIBDIR			?= lib
DEPDIR			?= .d
BINDIR			?= bin

# If in debug mode, compile with debug flags in a separate directory
ifeq ($(DEBUG),1)
	BINDIR		:= $(BINDIR)/debug
	C_FLAGS		+= $(C_FLAGS_DEBUG)
	LD_FLAGS	+= $(LD_FLAGS_DEBUG)
else
	BINDIR		:= $(BINDIR)/release
endif

# Template to generate linking rule (for each targets)
define LINKING_RULE_TEMPLATE
$(1)_BIN := $$(patsubst %.c,%.o,$$(addprefix $(BINDIR)/,$$($(1)_SRC)))
$(1): $$($(1)_BIN)
	@$(CC) $(LD_FLAGS) -I$(HDRDIR) -L./$(BINDIR) -o $(1) $$($(1)_BIN) $(addprefix -l,$($(1)_LIB))
	@echo "\033[32;1mCreated $(1)\033[0m"
endef

# Template to generate lib compilation rule
define COMPILE_LIB_TEMPLATE
$(1):
	@$(MAKE) -C $(LIBDIR)/$(LIB) TARGET_PATH='$(CURRENT_DIR)/$(BINDIR)'
endef

define INCLUDE_DEP_TEMPLATE
include $$(wildcard $$(patsubst %.c,$(DEPDIR)/%.d,$$($(1)_SRC)))
endef

##
# Rule definition
##

all: $(LIBS) $(TARGETS)

# Generate libraries compilation rules
$(foreach LIB,$(LIBS),$(eval $(call COMPILE_LIB_TEMPLATE,$(strip $(LIB)))))

# Generate linking rule for each target
$(foreach TARGET,$(TARGETS),$(eval $(call LINKING_RULE_TEMPLATE,$(strip $(TARGET)))))

# Compilation rule
$(BINDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*)
	@$(CC) $(C_FLAGS) $(DEP_FLAGS) -I$(HDRDIR) -o $@ -c $<
	@mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@
	@echo "\033[33mCompiling $@\033[0m"

$(DEPDIR)/%.d: ;

# Clean all binaries expect the targets..
clean:
	@rm -rf `dirname $(BINDIR)` $(DEPDIR)
	@$(MAKE) -C $(addprefix $(LIBDIR)/,$(LIBS)) $@

# ..clean targets binaries
fclean: clean
	@rm -f $(TARGETS)

re: fclean all

norm:
	@norminette $(SRCDIR) $(HDRDIR)

.PHONY: all clean fclean re norm
.PRECIOUS: $(DEPDIR)/%.d

# Include dependency files
$(foreach TARGET,$(TARGETS),$(eval $(call INCLUDE_DEP_TEMPLATE,$(strip $(TARGET)))))