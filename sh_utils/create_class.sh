#!/bin/bash

# Prompt the user for the directory where the script should be executed
echo "Enter the directory where you want to create the class files:"
read base_dir

# Check if the provided directory exists, and create it if it does not
if [ ! -d "$base_dir" ]; then
  echo "Directory does not exist. Creating directory."
  mkdir -p "$base_dir" || { echo "Failed to create directory. Exiting."; exit 1; }
fi

# Navigate to the specified directory
cd "$base_dir" || { echo "Failed to change directory. Exiting."; exit 1; }

# Prompt the user for the class name
echo "Enter the class name:"
read class_name

# Check if the class name is not empty
if [ -z "$class_name" ]; then
  echo "Class name cannot be empty. Exiting."
  exit 1
fi

# Convert class name to uppercase for include guards
class_name_upper=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')

# Header and source file names with specified paths
header_file="${class_name}.h"
source_file="${class_name}.cpp"

# Header file creation
cat <<EOF > $header_file
#ifndef ${class_name_upper}_H
#define ${class_name_upper}_H

class $class_name
{
public:
	/*** costructor ***/
	$class_name();
	/*** copy costructor ***/
	$class_name( const $class_name& other );
	/*** assignment operator ***/
	$class_name& operator=( const $class_name& other );
	/*** destructor ***/
	~$class_name();

private:
	/* Add private members here */
};

#endif
EOF

# Source file creation
cat <<EOF > $source_file
#include "$class_name.h"

/***  Costructor ***/
$class_name::$class_name() {}

/***  Copy costructor ***/
$class_name::$class_name( const $class_name& other ) {}

/***  assignment operator override ***/
$class_name& $class_name::operator=( const $class_name& other )
{
	if (this != &other)
	{
		// Assignment operator implementation
	}
	return *this;
}

/***  Destructor ***/
$class_name::~$class_name() {}

EOF

# User feedback
echo "Class $class_name created successfully!"
