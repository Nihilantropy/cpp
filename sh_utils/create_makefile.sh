#!/bin/bash

# Prompt the user for the directory where the Makefile should be created
echo "Enter the directory where you want to create the Makefile:"
read base_dir

# Check if the provided directory exists, and create it if it does not
if [ ! -d "$base_dir" ]; then
  echo "Directory does not exist. Creating directory."
  mkdir -p "$base_dir" || { echo "Failed to create directory. Exiting."; exit 1; }
fi

# Navigate to the specified directory
cd "$base_dir" || { echo "Failed to change directory. Exiting."; exit 1; }

# Prompt the user for the name of the target
echo "Enter the target name (NAME) for the Makefile:"
read target_name

# Create the Makefile
cat <<EOF > Makefile
# Variables
NAME = $target_name
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = ./
INC_DIR = ./
OBJ_DIR = obj

# Find all .cpp files in the srcs directory
SRCS = \$(wildcard \$(SRC_DIR)/*.cpp)

# Create a list of corresponding .o files in the obj directory
OBJS = \$(SRCS:\$(SRC_DIR)/%.cpp=\$(OBJ_DIR)/%.o)

# Main rule to build the target
all: \$(NAME)

# Rule to create the final target
\$(NAME): \$(OBJS)
	\$(CXX) \$(CXXFLAGS) -o \$@ \$^

# Rule to compile .cpp files into .o files
\$(OBJ_DIR)/%.o: \$(SRC_DIR)/%.cpp
	@mkdir -p \$(OBJ_DIR)
	\$(CXX) \$(CXXFLAGS) -I\$(INC_DIR) -c \$< -o \$@

# Rule to clean up generated files
clean:
	rm -rf \$(OBJ_DIR)

# Rule to clean up and recompile
fclean: clean
	rm -f \$(NAME)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re
EOF

# User feedback
echo "Makefile created successfully in $base_dir with target name '$target_name'!"
