#### Классы
I. ОСНОВНЫЕ СУЩНОСТИ:
   1. ConstructionCompany (полей: 4, методов: 3) -> ConstructionProject
   2. ConstructionProject (полей: 5, методов: 3) -> ProjectManager, Employee, Blueprint, Budget
   3. Building (полей: 5, методов: 3) -> Foundation, Wall, Roof, Floor
   4. ConstructionSite (полей: 5, методов: 3) -> ConstructionProject
   5. Employee (полей: 7, методов: 5) -> ConstructionCompany
   6. ProjectManager (полей: 2, методов: 2) -> Employee, ConstructionProject
   7. Architect (полей: 2, методов: 2) -> Employee, Blueprint
   8. ConstructionWorker (полей: 2, методов: 2) -> Employee, Equipment
   9. Supplier (полей: 5, методов: 3) -> BuildingMaterial
   10. Client (полей: 4, методов: 3) -> Contract
   11. Contract (полей: 5, методов: 3) -> Client, ConstructionCompany
   12. Budget (полей: 5, методов: 3) -> ConstructionProject
   13. Blueprint (полей: 5, методов: 3) -> ConstructionProject
   14. BuildingMaterial (полей: 5, методов: 3) -> ConstructionProject, Supplier
   15. Equipment (полей: 5, методов: 4) -> ConstructionProject

II. ПРОЕКТЫ И ПЛАНИРОВАНИЕ:
   16. ProjectPlan (полей: 5, методов: 3) -> ConstructionProject
   17. Schedule (полей: 5, методов: 4) -> ConstructionProject, Task
   18. Task (полей: 5, методов: 4) -> Employee, Equipment
   19. Milestone (полей: 5, методов: 3) -> ConstructionProject
   20. ResourceAllocation (полей: 5, методов: 3) -> ConstructionProject, Employee, Equipment
   21. CostEstimate (полей: 5, методов: 3) -> ConstructionProject
   22. RiskAssessment (полей: 5, методов: 3) -> ConstructionProject
   23. QualityStandard (полей: 5, методов: 3) -> ConstructionProject
   24. SafetyProtocol (полей: 5, методов: 3) -> ConstructionProject, Employee
   25. Permit (полей: 5, методов: 3) -> ConstructionProject

III. СТРОИТЕЛЬНЫЕ КОМПОНЕНТЫ:
   26. Foundation (полей: 5, методов: 3) -> Building
   27. Wall (полей: 5, методов: 3) -> Building
   28. Roof (полей: 5, методов: 3) -> Building
   29. Floor (полей: 5, методов: 3) -> Building
   30. ElectricalSystem (полей: 5, методов: 3) -> Building
   31. PlumbingSystem (полей: 5, методов: 3) -> Building
   32. HVACSystem (полей: 5, методов: 3) -> Building
   33. Elevator (полей: 5, методов: 3) -> Building
   34. Window (полей: 5, методов: 3) -> Building
   35. Door (полей: 5, методов: 3) -> Building

IV. СЕРВИСЫ И УПРАВЛЕНИЕ:
   36. ProjectManagementService (полей: 4, методов: 3) -> ConstructionProject
   37. BudgetService (полей: 4, методов: 3) -> Budget
   38. SchedulingService (полей: 4, методов: 3) -> Schedule
   39. InventoryService (полей: 4, методов: 3) -> BuildingMaterial
   40. HRService (полей: 4, методов: 3) -> Employee
   41. QualityControlService (полей: 4, методов: 3) -> QualityStandard
   42. SafetyInspectionService (полей: 4, методов: 3) -> SafetyProtocol
   43. ReportingService (полей: 4, методов: 3) -> ConstructionProject
   44. ClientManagementService (полей: 4, методов: 3) -> Client
   45. EquipmentMaintenanceService (полей: 4, методов: 3) -> Equipment
   46. MaterialOrderingService (полей: 4, методов: 3) -> BuildingMaterial, Supplier
   47. AnalyticsService (полей: 4, методов: 3) -> ConstructionProject
   48. ComplianceService (полей: 4, методов: 3) -> ConstructionProject
   49. DocumentManagementService (полей: 4, методов: 3) -> ConstructionProject
   50. WorkforceManagementService (полей: 4, методов: 3) -> Employee

ИСКЛЮЧЕНИЯ:
   1. BudgetExceededException
   2. ScheduleConflictException
   3. SafetyViolationException
   4. MaterialShortageException
   5. PermitNotGrantedException
   6. QualityStandardNotMetException 
   7. InvalidBlueprintException 
   8. EquipmentFailureException
   9. WorkerNotQualifiedException
   10. ClientPaymentDelayedException 
   11. WeatherConditionsException
   12. ResourceAllocationException

#### ВСЕГО:
Классов: 62 (50 основных + 12 исключений)
Полей: 193
Методов: 168
Ассоциаций: 43
