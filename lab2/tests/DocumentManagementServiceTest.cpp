#include <gtest/gtest.h>
#include "DocumentManagementService.h"

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

TEST(DocumentManagementServiceTest, CalculateDocumentAccuracyManyDocuments) {
    DocumentManagementService service("LARGE001", 800, 0.86);
    double accuracy = service.calculateDocumentAccuracy();
    EXPECT_GT(accuracy, 0);
}

TEST(DocumentManagementServiceTest, AutomateDocumentWorkflowYes) {
    DocumentManagementService service("DMS001", 300, 0.85);
    bool automated = service.automateDocumentWorkflow();
    EXPECT_TRUE(automated);
}

TEST(DocumentManagementServiceTest, AutomateDocumentWorkflowNo) {
    DocumentManagementService service("MANUAL001", 40, 0.82);
    bool automated = service.automateDocumentWorkflow();
    EXPECT_FALSE(automated);
}

TEST(DocumentManagementServiceTest, GetServiceId) {
    DocumentManagementService service("DOC003", 150, 0.91);
    EXPECT_EQ(service.getId(), "DOC003");
}
