program fortBinding
use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT, C_DOUBLE
implicit none
interface 
  subroutine yaml_event_reader(filePath) bind(C, name="yamlEventReader")
    use iso_c_binding, only: C_CHAR
    character(kind=C_CHAR) :: filePath(*)
  end subroutine yaml_event_reader

  real(C_DOUBLE) function get_variable_for_component(comp_num, var_name, system) bind(C, name="getVariableForComponent")
      use iso_c_binding, only: C_CHAR, C_NULL_CHAR, C_INT, C_DOUBLE
      integer(C_INT) :: comp_num
      character(kind=C_CHAR) :: var_name(*)
      character(kind=C_CHAR, len=72) :: system(*)
  end function
end interface

type Component
   integer(C_INT) :: number
   real(C_DOUBLE) :: friction_design_factor
   real(C_DOUBLE) :: interfactial_design_factor
   real(C_DOUBLE) :: design_factor1
   real(C_DOUBLE) :: design_factor2
   real(C_DOUBLE) :: design_factor3
   real(C_DOUBLE) :: design_factor4
   real(C_DOUBLE) :: design_factor5
   character(kind=C_CHAR, len=72) :: system  
end type Component   

type(Component) :: volume_g ! wants only global design factor
type(Component) :: volume_sys ! wants only system design factor
type(Component) :: volume_loc ! wants only local design factor
type(Component) :: volume_sys_loc ! wants system and local
type(Component) :: volume_g_loc ! wants global and local
type(Component) :: volume_g_sys ! wants global and system
type(Component) :: volume_g_sys_loc ! want global system and local
!character(kind=c_char, len=*), parameter :: gtag_file = "../yamlFiles/global-tag.yaml" // c_null_char !! Not currently supporting
!global tags

character(kind=c_char, len=*), parameter :: nYaml_file = "../yamlFiles/nYaml.yaml" // c_null_char
logical :: isTF ! is true false?

volume_g%number=100
volume_sys%number=111
volume_sys%system="Primary"
volume_loc%number=122
volume_loc%design_factor5 = 33.333
volume_sys_loc%number=200
volume_sys_loc%system="Secondary"
volume_g_loc%number=300
volume_g_sys%number=400
volume_g_sys%system="LOCCA"
volume_g_sys_loc%number=500
volume_g_sys_loc%system="Primary"
!call yaml_event_reader(gtag_file) 
call yaml_event_reader(nYaml_file) 

end program fortBinding  

!function isPartofSystemName(comp%system, arg) result(tf)
!    character(kind=c_char, len=*) :: arg ! from cpp dictionary
!    character(len=*) :: comp%system      ! from fortran structure
!    logical :: tf ! true or false
!
!    tf = arg == comp%system
!
!end function
