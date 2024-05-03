# Database Manager Application

This is a simple database manager application built using Qt and SQLite.

## Features

- Connects to a SQLite database.
- Creates a table named `people` with fields `id` and `name`.
- Provides functions to add, check existence, remove, print all records, and remove all records of people in the database.

## Code Structure

The application is structured into a single `DbManager` class. The `DbManager` class handles the connection to the SQLite database and provides the database operations.

### Database Connection

The database connection is established in the `DbManager` constructor. It opens the SQLite database at the given path and creates the `people` table if it doesn't exist.

### Database Operations

The `DbManager` class provides the following database operations:

- `addPerson`: Adds a new person to the `people` table.
- `personExists`: Checks if a person exists in the `people` table.
- `removePerson`: Removes a person from the `people` table.
- `printAll`: Prints all people in the `people` table.
- `removeAll`: Removes all people from the `people` table.

## Building and Running

To build and run the application, you need to have Qt and SQLite installed on your system. You can then use the Qt Creator IDE to open the `.pro` file and build the application.

Please note that you need to adjust the include and library paths in the `.pro` file to match the locations of the Qt and SQLite installations on your system.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
README

# Visual Database Manager

## Overview

The Visual Database Manager is a user-friendly application that allows users to manage a `SQLite` database with ease. Users can add, remove, and search for people in the database, and perform various other operations.

## Key Features:

Intuitive graphical user interface
CRUD operations (Create, Read, Update, Delete) for managing people in the database
Database connection and table creation
Error handling and feedback
## Technical Specifications:

Built using `Qt 5` and `SQLite`
SQLite database file located at `C:/Users/Hp/Desktop/DataBase/database/people.db`
Compatible with `Windows`, `macOS`, and `Linux` operating systems
## Usage:

To use the Visual Database Manager:

- Open the application.
- Enter a name in the “Name” field.
- Click one of the buttons to perform the desired action.
## Database Operations:

The application supports the following database operations:

- Add Person: Adds a new person to the database.
- Remove Person: Removes a person from the database.
- Print All: Displays all people in the database.
- Remove All: Removes all people from the database.
- Check Exists: Checks if a person exists in the database.
## Building and Running:

To build and run the application:

- Ensure that Qt 5 and SQLite are installed on your system.
- Open the .pro file in a Qt IDE (e.g.,` Qt Creator`).
- Adjust the include and library paths to match the locations of `Qt` and `SQLite` on your system.
- Build and run the application.
## License:

The Visual Database Manager is licensed under the MIT License.
