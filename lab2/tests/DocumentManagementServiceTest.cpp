#include <gtest/gtest.h>
#include "DocumentManagementService.h"
#include "ConstructionProject.h"
#include "Blueprint.h"

TEST(DocumentManagementServiceTest, CalculateDocumentAccuracyHigh) {
    DocumentManagementService service("DOC001", 200, 0.94);
    double accuracy = service.calculateDocumentAccuracy();
    EXPECT_GT(accuracy, 90.0);
}

TEST(DocumentManagementServiceTest, CalculateDocumentAccuracyLow) {
    DocumentManagementService service("DOC002", 500, 0.65);
    double accuracy = service.calculateDocumentAccuracy();
    EXPECT_LT(accuracy, 70.0);
}

TEST(DocumentManagementServiceTest, AutomateDocumentWorkflowYes) {
    DocumentManagementService service("DMS001", 300, 0.85);
    bool automated = service.automateDocumentWorkflow();
    EXPECT_TRUE(automated);
}

TEST(DocumentManagementServiceTest, CalculateServicePerformance) {
    DocumentManagementService service("DOC003", 150, 0.91);
    double performance = service.calculateServicePerformance();
    EXPECT_GT(performance, 0.0);
}

TEST(DocumentManagementServiceTest, NeedsSystemUpgrade) {
    DocumentManagementService service("MANUAL001", 40, 0.72);
    bool needsUpgrade = service.needsSystemUpgrade();
    EXPECT_TRUE(needsUpgrade);
}

TEST(DocumentManagementServiceTest, AddAndGetProjectDocuments) {
    DocumentManagementService service("DOC004", 100, 0.88);
    ConstructionProject project1("P1", "Project 1", 500000, 12);
    ConstructionProject project2("P2", "Project 2", 300000, 8);
    
    service.addProjectDocument(&project1);
    service.addProjectDocument(&project2);
    
    auto projects = service.getProjectDocuments();
    EXPECT_EQ(projects.size(), 2);
}

TEST(DocumentManagementServiceTest, AddAndGetManagedBlueprints) {
    DocumentManagementService service("DOC005", 120, 0.90);
    Blueprint blueprint1("BP1", "P1", 1, 1.0);
    Blueprint blueprint2("BP2", "P2", 1, 1.5);
    
    service.addManagedBlueprint(&blueprint1);
    service.addManagedBlueprint(&blueprint2);
    
    auto blueprints = service.getManagedBlueprints();
    EXPECT_EQ(blueprints.size(), 2);
}
