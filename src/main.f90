program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT, C_PTR
implicit none
interface 
  function yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char, c_ptr
    character(kind=c_char) :: filePath(*)
    type(c_ptr) :: yaml_event_reader
  end function yaml_event_reader 
end interface

!! Pointer to the C++ Factory
type(c_ptr) :: fact_ptr

!! Not currently supporting global tags
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char


!call yaml_event_reader
fact_ptr = yaml_event_reader(nYaml_file) 

end program 
