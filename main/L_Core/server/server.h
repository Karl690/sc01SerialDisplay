#pragma once

#define SERVER_PORT		5000

bool server_start();
void server_stop();

void server_client_close(int socketid);
bool servier_is_status();
void server_send_broadcast(uint8_t* buf, int size);