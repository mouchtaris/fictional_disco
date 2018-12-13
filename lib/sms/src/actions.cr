# vim: et ts=2 sw=2

module Actions
  module Action
    include ::Logging
    include ::ConfDirViews
  end
end

require "./actions/generate_cmake"

module Actions
  include GenerateCMake
end
