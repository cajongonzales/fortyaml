program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT
implicit none
interface 
  subroutine yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: c_char
    character(kind=c_char) :: filePath(*)
  end subroutine yaml_event_reader 
end interface

type Component
   integer :: number
   real :: friction_design_factor
   character(len=72) :: system
end type Component   

type(Component) :: volume_Global
type(Component) :: volume_System
type(Component) :: volume_Local
!! Not currently supporting global tags
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char
character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char


!call yaml_event_reader(gtag_file) 
call yaml_event_reader(nYaml_file) 

end program 
