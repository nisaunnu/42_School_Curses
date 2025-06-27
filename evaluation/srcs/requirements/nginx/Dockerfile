FROM debian:bullseye

# Install Nginx and OpenSSL
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Copy configuration
COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf

# Copy setup script
COPY tools/nginx_setup.sh /usr/local/bin/nginx_setup.sh
RUN chmod +x /usr/local/bin/nginx_setup.sh

# Create directories
RUN mkdir -p /etc/nginx/ssl \
    && mkdir -p /var/run/nginx \
    && mkdir -p /var/www/html

# Expose port
EXPOSE 443

# Set entrypoint
ENTRYPOINT ["/usr/local/bin/nginx_setup.sh"]
