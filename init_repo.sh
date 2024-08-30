#!/bin/bash

# Function to ask for user input
ask_user()
{
	local prompt="$1"
	local input

	read -r -p "$prompt: " input
	echo "$input"
}

# Function to find the script path
find_script_path()
{
	local script_name="$1"
	local script_path="$starting_dir/sh_utils/$script_name"

	if [ -f "$script_path" ]; then
		echo "$script_path"
	else
		echo ""
	fi
}

# Save the starting directory
starting_dir=$(pwd)

# Step 1: Ask for the folder name
folder_name=$(ask_user "Enter the folder name or path to initialize the repository")

# Create the folder structure
if [ ! -d "$folder_name" ]; then
	mkdir -p "$folder_name"
fi

# Change directory to the created folder
cd "$folder_name" || exit

# Create 'include' and 'srcs' subfolders
mkdir -p include srcs

# Create 'main.cpp' in the 'srcs' directory if it doesn't exist
main_file="srcs/main.cpp"
if [ ! -f "$main_file" ]; then
	cat <<EOF > "$main_file"
// Add dependencies

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
}
EOF
	echo "main.cpp created in srcs directory."
fi

# Step 2: Ask if user wants to add a Makefile
add_makefile=$(ask_user "Do you want to add a Makefile? (yes/no)")

if [ "$add_makefile" = "yes" ] || [ -z "$add_makefile" ]; then
	# Call the script to create the Makefile
	script_path=$(find_script_path "create_makefile.sh")
	if [ -n "$script_path" ]; then
		/bin/bash "$script_path"
	else
		echo "Script create_makefile.sh not found!"
	fi
fi

# Step 3: Ask if user wants to create a new class
create_class=$(ask_user "Do you want to create a new class? (yes/no)")

if [ "$create_class" = "yes" ] || [ -z "$create_class" ]; then
	# Call the script to create a new class
	script_path=$(find_script_path "create_class.sh")
	if [ -n "$script_path" ]; then
		/bin/bash "$script_path"
	else
		echo "Script create_class.sh not found!"
	fi
fi

echo "Initialization complete!"
