#include "ClientPaymentDelayedException.h"

ClientPaymentDelayedException::ClientPaymentDelayedException(const std::string& client, int delay)
    : std::runtime_error("Client payment delayed: " + client + " - delay: " + std::to_string(delay) + " days"),
      clientId(client), delayDays(delay) {}

std::string ClientPaymentDelayedException::getClientId() const {
    return clientId;
}

int ClientPaymentDelayedException::getDelayDays() const {
    return delayDays;
}
