program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT
implicit none
interface 
  subroutine yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char
    character(kind=c_char) :: filePath(*)
  end subroutine yaml_event_reader 
end interface

character(kind=c_char, len=*), parameter :: input_file = "../yamlFiles/anchors.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: file_path = "../yamlFiles/nYaml.yaml" // c_null_char

call yaml_event_reader(input_file) 
call yaml_event_reader(file_path) 
end program 
