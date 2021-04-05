program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT
implicit none
interface 
  subroutine yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char
    character(kind=c_char) :: filePath(*)
  end subroutine yaml_event_reader 
end interface

character(kind=c_char, len=*), parameter :: anchors_file = "../yamlFiles/anchors.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: array_file = "../yamlFiles/array.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: json_file = "../yamlFiles/json.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: mapping_file = "../yamlFiles/mapping.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: numbers_file = "../yamlFiles/numbers.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: strings_file = "../yamlFiles/strings.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: tags_file = "../yamlFiles/tags.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: yamlVer_file = "../yamlFiles/yaml-version.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char

call yaml_event_reader(anchors_file) 
call yaml_event_reader(array_file) 
call yaml_event_reader(gtag_file) 
call yaml_event_reader(json_file) 
call yaml_event_reader(mapping_file) 
call yaml_event_reader(numbers_file) 
call yaml_event_reader(strings_file) 
call yaml_event_reader(tags_file) 
call yaml_event_reader(yamlVer_file) 
call yaml_event_reader(nYaml_file) 
end program 
