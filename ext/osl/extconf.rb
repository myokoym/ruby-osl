require "mkmf"

if have_library("osl")
  create_makefile("osl/osl")
end
