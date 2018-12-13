# vim: et ts=2 sw=2

module Actions
  module Action
    include ::Logging
    include ::ConfDirViews
  end
end

require "./actions/generate_cmake"
require "./actions/generate_source_files"
require "./actions/generate_header_files"

module Actions
  include GenerateCMake
  include GenerateSourceFiles
  include GenerateHeaderFiles
end
