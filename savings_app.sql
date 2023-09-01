-- Step 1: Connect to MySQL and create a new database
CREATE DATABASE savings_app;

-- Step 2: Switch to the new database
USE savings_app;

-- Step 3: Create a table to store user profiles
CREATE TABLE user_profiles (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    password VARCHAR(255) NOT NULL
    -- Add more profile fields as needed
);

-- Step 4: Create a table to store savings data associated with users
CREATE TABLE savings_data (
    savings_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    date DATE NOT NULL,
    description VARCHAR(255),
    FOREIGN KEY (user_id) REFERENCES user_profiles(user_id)
);

-- Step 5: Create a new user with privileges on the database
CREATE USER 'app_user'@'localhost' IDENTIFIED BY 'password';

-- Step 6: Grant privileges to the user on the database
GRANT SELECT, INSERT, UPDATE, DELETE ON savings_app.* TO 'app_user'@'localhost';

-- Step 7: Flush privileges to apply changes
FLUSH PRIVILEGES;

