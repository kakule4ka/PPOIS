## Классы:

1. **ConstructionCompany** (полей: 5, методов: 10) -> ConstructionProject, Employee
2. **ConstructionProject** (полей: 7, методов: 10) -> ProjectManager, Employee, Budget
3. **Building** (полей: 7, методов: 8) -> ConstructionProject, Foundation, ElectricalSystem
4. **ConstructionSite** (полей: 6, методов: 8) -> ConstructionProject, SafetyProtocol
5. **Employee** (полей: 5, методов: 8) -> ConstructionProject
6. **ProjectManager** (полей: 5, методов: 8) : Employee -> ConstructionProject, Budget, Schedule
7. **Architect** (полей: 5, методов: 8) : Employee -> Blueprint, ConstructionProject, QualityStandard
8. **ConstructionWorker** (полей: 4, методов: 8) : Employee -> Task, SafetyProtocol
9. **Supplier** (полей: 6, методов: 8) -> BuildingMaterial, ConstructionProject
10. **Client** (полей: 5, методов: 8) -> ConstructionProject, Contract
11. **Contract** (полей: 7, методов: 8) -> Client, ConstructionCompany, ConstructionProject
12. **Budget** (полей: 6, методов: 8) -> ConstructionProject, CostEstimate
13. **Blueprint** (полей: 6, методов: 8) -> ConstructionProject, BuildingMaterial
14. **BuildingMaterial** (полей: 6, методов: 8) -> ConstructionProject, Supplier
15. **Equipment** (полей: 6, методов: 8) -> ConstructionProject, Employee
16. **ProjectPlan** (полей: 7, методов: 8) -> ConstructionProject, RiskAssessment, Schedule
17. **Schedule** (полей: 7, методов: 10) -> ConstructionProject, Task, Milestone
18. **Task** (полей: 7, методов: 10) -> Employee, BuildingMaterial, Equipment
19. **Milestone** (полей: 6, методов: 8) -> ConstructionProject, Task
20. **ResourceAllocation** (полей: 7, методов: 8) -> ConstructionProject, Employee, Equipment
21. **CostEstimate** (полей: 7, методов: 10) -> ConstructionProject, BuildingMaterial, Equipment
22. **RiskAssessment** (полей: 6, методов: 8) -> ConstructionProject, SafetyProtocol
23. **QualityStandard** (полей: 6, методов: 8) -> ConstructionProject, BuildingMaterial
24. **SafetyProtocol** (полей: 7, методов: 10) -> ConstructionProject, Employee, Equipment
25. **Permit** (полей: 6, методов: 8) -> ConstructionProject, QualityStandard
26. **Foundation** (полей: 6, методов: 8) -> Building, QualityStandard
27. **Wall** (полей: 6, методов: 8) -> Building, BuildingMaterial
28. **Roof** (полей: 6, методов: 8) -> Building, BuildingMaterial
29. **Floor** (полей: 6, методов: 8) -> Building, BuildingMaterial
30. **ElectricalSystem** (полей: 6, методов: 8) -> Building, QualityStandard
31. **PlumbingSystem** (полей: 6, методов: 8) -> Building, QualityStandard
32. **HVACSystem** (полей: 6, методов: 8) -> Building, QualityStandard
33. **Elevator** (полей: 6, методов: 8) -> Building, SafetyProtocol
34. **Window** (полей: 6, методов: 8) -> Building, QualityStandard
35. **Door** (полей: 6, методов: 8) -> Building, SafetyProtocol
36. **ProjectManagementService** (полей: 3, методов: 2) -> 
37. **BudgetService** (полей: 5, методов: 8) -> ConstructionProject, Budget
38. **SchedulingService** (полей: 3, методов: 2) -> 
39. **InventoryService** (полей: 4, методов: 4) -> BuildingMaterial
40. **HRService** (полей: 5, методов: 8) -> Employee, ConstructionProject
41. **QualityControlService** (полей: 4, методов: 4) -> QualityStandard
42. **SafetyInspectionService** (полей: 3, методов: 2) -> 
43. **ReportingService** (полей: 4, методов: 4) -> ConstructionProject
44. **ClientManagementService** (полей: 5, методов: 8) -> Client, Contract
45. **EquipmentMaintenanceService** (полей: 5, методов: 8) -> Equipment, ConstructionProject
46. **MaterialOrderingService** (полей: 4, методов: 4) -> Supplier
47. **DocumentManagementService** (полей: 5, методов: 8) -> ConstructionProject, Blueprint
48. **AnalyticsService** (полей: 5, методов: 8) -> ConstructionProject, RiskAssessment
49. **ComplianceService** (полей: 5, методов: 8) -> ConstructionProject, QualityStandard
50. **WorkforceManagementService** (полей: 3, методов: 2) -> 

## Исключения:

1. **BudgetExceededException**
2. **ScheduleConflictException**
3. **SafetyViolationException**
4. **MaterialShortageException**
5. **PermitNotGrantedException**
6. **QualityStandardNotMetException**
7. **InvalidBlueprintException**
8. **EquipmentFailureException**
9. **WorkerNotQualifiedException**
10. **ClientPaymentDelayedException**
11. **WeatherConditionsException**
12. **ResourceAllocationException**

## Всего:

**Классов:** 50 + 12 исключений  
**Полей:** 270  
**Методов:** 362 + Set и Get функции  
**Ассоциаций:** 78 (без исключений)
