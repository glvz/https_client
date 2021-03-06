

#ifndef HTTPS_CLIENT_IMPL_CLIENT_INTERFACE_H
#define HTTPS_CLIENT_IMPL_CLIENT_INTERFACE_H

#include "include.h"
#include "smatr_ptrs.h"

namespace simple_https {

    using read_func = std::function<std::string()>;
    using write_func = std::function<void(std::string_view)>;

    class client_interface {
        std::string hostname{};
        virtual std::string read();
        virtual void write(const std::string &request_str);
    protected:
        client_interface(const std::string &host);
        inline std::string prepare_request(const std::string &req);
    public:
        std::string get_request(const std::string &req);
        virtual void reload();
    };

}


#endif //HTTPS_CLIENT_IMPL_CLIENT_INTERFACE_H
