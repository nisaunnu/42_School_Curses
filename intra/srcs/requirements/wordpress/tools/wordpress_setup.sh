#!/bin/bash

# Read passwords from secrets
DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(grep WP_ADMIN_PASSWORD /run/secrets/credentials | cut -d'=' -f2)
WP_USER_PASSWORD=$(grep WP_USER_PASSWORD /run/secrets/credentials | cut -d'=' -f2)

# Wait for database to be ready
echo "Waiting for database..."
while ! mysqladmin ping -h"${DB_HOST}" --silent; do
    sleep 1
done

# Download WordPress if not exists
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Setting up WordPress..."

    # Download WordPress
    # Set permissions
    chown -R www-data:www-data /var/www/html
    chmod -R 755 /var/www/html

    cd /var/www/html

	wp-cli core download --allow-root

    # Create wp-config.php
    wp-cli config create --dbname="${DB_NAME}" --dbuser="${DB_USER}" --dbpass="${DB_PASSWORD}" --dbhost="${DB_HOST}" --allow-root

    # Install WordPress
    wp-cli core install --url="${DOMAIN_NAME}" --title="Inception WordPress" --admin_user="${WP_ADMIN_USER}" --admin_password="${WP_ADMIN_PASSWORD}" --admin_email="${WP_ADMIN_EMAIL}" --allow-root

    # Create additional user
    wp-cli user create "${WP_USER}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASSWORD}" --role=author --allow-root

    echo "WordPress setup completed."
fi

# Start PHP-FPM in foreground
exec php-fpm7.4 -F
