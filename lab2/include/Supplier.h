#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
private:
    std::string id;
    std::string name;
    std::string material;
    double reliability;
    
public:
    Supplier(const std::string& id, const std::string& name, const std::string& material, double reliability);
    
    double calculateDeliveryRisk() const;
    bool canHandleUrgentOrder() const;
    
    std::string getId() const { return id; }
};

#endif
