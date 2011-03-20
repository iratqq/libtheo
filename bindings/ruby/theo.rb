require 'rubygems'
gem 'ffi'
require 'ffi'

module TheoLib
  extend FFI::Library
  ffi_lib "libtheo.so"
  attach_function :theo, [], :pointer
end

def theo()
  return TheoLib.theo().read_string()
end

