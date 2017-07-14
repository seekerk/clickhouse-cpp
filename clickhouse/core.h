#pragma once

namespace clickhouse {

class CompletionQueue {
public:
    bool Next(void** tag, bool* ok);
};

class AsyncClient {
public:
     AsyncClient(CompletionQueue* cq);
    ~AsyncClient();

    /// Initiate handshake with server.
    void Handshake(void* tag);

    /// Initiate ping to server.
    void Ping(void* tag);

private:
    CompletionQueue* const cq_;
};

/*

    Основные концепции
        - Очередь завершённых событий
        - Сессия взаимодействия с сервером (одно tcp-соединение)

    Команды:
        - Handshake
        - Ping
        - Query
        - SendBlock
        - ReceiveBlock
        - Cancel


*/
} // namespace clickhouse
