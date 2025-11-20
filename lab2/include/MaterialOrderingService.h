#ifndef MATERIALORDERINGSERVICE_H
#define MATERIALORDERINGSERVICE_H

#include <string>

class MaterialOrderingService {
private:
    std::string serviceId;
    int ordersProcessed;
    double deliveryAccuracy;
    
public:
    MaterialOrderingService(const std::string& id, int orders, double accuracy);
    
    double calculateOrderEfficiency() const;
    bool optimizeOrderQuantity() const;
    
    std::string getId() const { return serviceId; }
};

#endif
