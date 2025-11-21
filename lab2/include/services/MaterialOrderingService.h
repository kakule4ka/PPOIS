#ifndef MATERIALORDERINGSERVICE_H
#define MATERIALORDERINGSERVICE_H

#include <string>
#include <vector>

class Supplier;

class MaterialOrderingService {
private:
    std::string serviceId;
    int ordersProcessed;
    double deliveryAccuracy;
    std::vector<Supplier*> approvedSuppliers; // +1 ассоциация
    
public:
    MaterialOrderingService(const std::string& id, int orders, double accuracy);
    
    double calculateOrderEfficiency() const;
    bool optimizeOrderQuantity() const;
    
    // Ассоциация
    void addSupplier(Supplier* supplier);
    std::vector<Supplier*> getApprovedSuppliers() const;
    
    std::string getId() const { return serviceId; }
};

#endif
