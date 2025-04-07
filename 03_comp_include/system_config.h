struct passage_config {
    enum passage_mode mode;          // Passage operation mode
    char passage_name[64];           // Name of passage
    struct {
        int buffer_size;             // Size of passage buffer
        void* buffer;                // Buffer pointer
        int current_pos;             // Current buffer position
    } buffer_info;
    struct {
        enum vine_type type;         // Internal/External vine
        enum vine_mode mode;         // Vine operation mode
        int connection_id;           // Connection identifier
    } vine_info;
    struct {
        int is_blocking;             // Blocking/non-blocking
        int timeout_ms;              // Timeout in milliseconds
        int retry_count;             // Number of retry attempts
    } operation_info;
    int status;                      // Current passage status
};

struct port_hub_config {
    char host_name[256];             // Host name/IP
    int port;                        // Port number
    struct {
        int protocol_type;           // TCP/UDP/Custom
        int socket_type;             // Socket type
        int socket_family;           // Socket family
    } connection_info;
    struct {
        int buffer_size;             // Network buffer size
        int timeout_ms;              // Connection timeout
        int retry_count;             // Connection retries
    } settings;
    struct {
        int is_server;               // Server/Client mode
        int max_connections;         // Max concurrent connections
        int current_connections;     // Current active connections
    } server_info;
    int status;                      // Current network status
};

struct file_config {
    char file_name[256];             // File name
    char file_path[1024];            // File path
    struct {
        int read_access;             // Read permission
        int write_access;            // Write permission
        int create_access;           // Create permission
        int append_access;           // Append permission
    } permissions;
    struct {
        long size;                   // File size
        long position;               // Current position
        int is_binary;              // Binary/Text mode
    } file_info;
    struct {
        int buffer_size;             // File buffer size
        void* buffer;                // Buffer pointer
        int buffer_pos;             // Buffer position
    } buffer_info;
    int status;                      // Current file status
};
