    inline auto update_camera() -> void
    {
        // update camera logic..

        this->local_camera.matrix = // update your rotation like you do in your w2s
        this->local_camera.inverted_field_of_view = // update your fov like you do in ur w2s
    }

    __forceinline auto world_to_screen(fvector project_location) const -> fvector2d
    {
        const auto matrix = this->local_camera.matrix;
        const auto delta = project_location - this->local_camera.location;
        const auto adjusted_z = this->local_camera.inverted_field_of_view / (std::max)(delta.dot(fvector(matrix.m[0][0], matrix.m[0][1], matrix.m[0][2])), 1.0);

        return {
            monitor.width_center + static_cast<float>((delta.x * matrix.m[1][0] + delta.y * matrix.m[1][1] + delta.z * matrix.m[1][2]) * adjusted_z),
            monitor.height_center - static_cast<float>((delta.x * matrix.m[2][0] + delta.y * matrix.m[2][1] + delta.z * matrix.m[2][2]) * adjusted_z)
        };
    }
