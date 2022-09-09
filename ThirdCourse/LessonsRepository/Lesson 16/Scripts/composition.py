import json

class PetExport:
    def export(self, dog):
        # не будем создавать экземпляров класса,
        # он нужен только для наследования
        raise NotImplementedError
    
class ExportDogXML(PetExport):
    def export(self, dog):
        return """<?xml version="1.0" encoding="utf-8"?>
<dog>
   <name>{0}</name>
   <breed>{1}</breed>
   <noise>{2}</noise>
   <harm>{3}</harm>
   <guard>{4}</guard>
</dog>""".format(dog.name, dog.breed, dog.noise, dog.harm, dog.guard)
    
class ExportDogJSON(PetExport):
    def export(self, dog):
        return json.dumps({
            "name": dog.name,
            "breed": dog.breed,
            "noise": dog.noise,
            "harm": dog.harm,
            "guard": dog.guard
        })
    
class ComposedExpDog(Dog):
    def __init__(self, name, breed=None, exporter=None):
        super().__init__(name, breed)
        self.__exporter = exporter or ExportDogJSON()
        if not isinstance(self.__exporter, PetExport):
            raise ValueEror("Параметр экземпляра __exporter неправильного типа")
        
    def export(self):
        return self.__exporter.export(self)
