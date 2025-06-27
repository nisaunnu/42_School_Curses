#!/bin/bash

# Read passwords from secrets
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
DB_PASSWORD=$(cat /run/secrets/db_password)

# Initialize database if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Start MariaDB in background
mysqld_safe --user=mysql &

# Wait for MariaDB to start
while ! mysqladmin ping --silent; do
    sleep 1
done

# Check if database exists
if ! mysql -u root -e "USE ${MYSQL_DATABASE};" 2>/dev/null; then
    echo "Setting up MariaDB..."


    # Create database and user
    mysql -u root -p"${DB_ROOT_PASSWORD}" <<EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    echo "MariaDB setup completed."
fi

# Stop background process
mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown

# Start MariaDB in foreground
exec mysqld_safe --user=mysql
