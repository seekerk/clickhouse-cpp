#include "core.h"

namespace clickhouse {

AsyncClient::AsyncClient(CompletionQueue* cq)
    : cq_(cq)
{
}

AsyncClient::~AsyncClient()
{ }

void AsyncClient::Handshake(void* tag) {
    (void)tag;
    // 1. создать tcp-соединение
    // 2. сформировать сериализованный запрос.
    // 3. отправить блок данных асинхронно.
    // 4. перейти в состояние получения блока
}


} // namespace clickhouse
